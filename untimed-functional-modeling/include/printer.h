#ifndef _PRINTER_H_
#define _PRINTER_H_

#include <systemc>

using namespace sc_core;

template <class T>
class Printer : public sc_module {
  public:
    sc_fifo_in<T> input;

    SC_HAS_PROCESS(Printer);

    Printer(sc_module_name name, unsigned iter_num) : sc_module(name), iter_num_(iter_num),
      done_(false) {
      SC_THREAD(process);
    }

    ~Printer() {
      if (!done_) std::cout << "@" << sc_time_stamp() << " " << name() << " not done yet" << std::endl;
    }

    void process() {
      for (unsigned i = 0; i < iter_num_; i++) {
        T value = input.read();
        std::cout << "@" << sc_time_stamp() << " " << name() << " " << value << std::endl;
      }
      done_ = true;
    }

  private:
    unsigned iter_num_;
    bool done_;
};

#endif /* _PRINTER_H_ */


