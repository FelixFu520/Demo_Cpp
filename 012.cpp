// https://mp.weixin.qq.com/s?__biz=MzkzMTY3NDYwNQ==&mid=2247484529&idx=1&sn=d6e129d435d4d5ac40a25cc4582c7657&chksm=c26624f3f511ade5c28162a8f9bb9f79550cbda40e42b1e924c3f69c707f494d9400431f006a&cur_album_id=3386784075163844618&scene=189#wechat_redirect
#pragma once

#include <memory>
#include <functional>
#include <iostream>
#include <thread>
#include <mutex>
#include <string>

// gdb_test_sample.h
struct Person {
  std::string name;
  int age =0;
};

class Gdb_Sample {
 public:
  Gdb_Sample()=default;
  ~Gdb_Sample();

  void Core();
  void DeadLock();
  void Normal();
  void ThreadSchedulerMutex();
 
 private:
  void threadFunc1();
  void threadFunc2();
  void fun_int(int& n);
  void fun_string(const std::string& s);
  void fun_struct(const Person& msg);
 
 private:
   std::mutex mutex1_;
   std::mutex mutex2_;

   std::thread thread1_;
   std::thread thread2_;
   std::shared_ptr<std::thread> thread3_;
   std::shared_ptr<std::thread> thread4_;
   std::shared_ptr<std::thread> thread5_;
};

// gdb_test_sample.cpp
Gdb_Sample::~Gdb_Sample() {
  if(thread1_.joinable()) {
    thread1_.join();
  }

  if(thread2_.joinable()) {
    thread2_.join();
  }

  if(thread3_->joinable()) {
    thread3_->join();
  }

  if(thread4_->joinable()) {
    thread4_->join();
  }

  if(thread5_->joinable()) {
    thread5_->join();
  }
}

void Gdb_Sample::Core() {
  int v[] = {0, 1, 2, 3, 4};
  int size = 1000;
  for (int i = 0; i < size; ++i) {
    if (i > 4) {
      int *ptr = NULL;
      *ptr = 10;  // 引发段错误
    }
    std::cout << " i " << i << " vaule " << v[i] << std::endl; 
  }
}

void Gdb_Sample::DeadLock() {
  thread1_ = std::thread(&Gdb_Sample::threadFunc1, this);
  thread2_ = std::thread(std::bind(&Gdb_Sample::threadFunc2, this));
}

void Gdb_Sample::ThreadSchedulerMutex() {
  int num = 1;
  thread3_ = std::make_shared<std::thread>(std::bind(&Gdb_Sample::fun_int, this, std::placeholders::_1),
     std::ref(num));
  
  std::string str ="test";
  thread4_ = std::make_shared<std::thread>([this, str](const std::string& s){
    fun_string(str);
  }, std::ref(str));

  Person person;
  person.name = "xxx";
  person.age = 10;
  thread5_ = std::make_shared<std::thread>(std::bind(&Gdb_Sample::fun_struct, this, std::placeholders::_1),
    std::ref(person));
}

void Gdb_Sample::threadFunc1() {
  std::lock_guard<std::mutex> lock1(mutex1_);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::lock_guard<std::mutex> lock2(mutex2_);
  std::cout << "Thread 1 acquired both locks" << std::endl;
}

void Gdb_Sample::threadFunc2() {
  std::lock_guard<std::mutex> lock2(mutex2_);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::lock_guard<std::mutex> lock1(mutex1_);
  std::cout << "Thread 2 acquired both locks" << std::endl;
}

void Gdb_Sample::fun_int(int& n) {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  int i = 0;
  for (; i < 10; ++i) {
    std::cout << "in fun_int n = " << n << std::endl;
  }
}

void Gdb_Sample::fun_string(const std::string& s) {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  int i = 0;
  for (; i < 10; ++i) {
    std::cout << "in fun_string s = " << s << std::endl;
  }
}

void Gdb_Sample::fun_struct(const Person& msg) {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  for (int i =0; i < 10; ++i) {
    std::cout << "in fun_struct name = " << msg.name << " age " << msg.age
            << std::endl;
  }
}

// main.cc
//  g++ -g -Wall  -o tmp main.cpp
// gdb --args ./gdb_test_sample schedule/core/deadlock
int main(int argc, char** argv) {
    auto gdb_sample = std::make_unique<Gdb_Sample>();
    std::string cmd = std::string(argv[1]);
    if (gdb_sample) {
      if (argc > 1) {
        if (cmd == "core") {
          std::cout << " core sample " << std::endl;
           gdb_sample->Core();
        } else if (cmd == "deadlock") {
          std::cout << " DeadLock sample " << std::endl;
           gdb_sample->DeadLock();
        } else if (cmd == "schedule") {
          gdb_sample->ThreadSchedulerMutex();
          std::cout << " schedule sample " << std::endl;
        }
      }
    }

    return 0;
}