#include <chrono>
#include <thread>

void sleep(int ms) {
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void slow() {
  sleep(1000);
}

void fast() {
  sleep(100);
}

int main() {
  fast();
  slow();
}
