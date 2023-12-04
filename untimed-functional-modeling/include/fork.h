#ifndef _FORK_H_
#define _FORK_H_

#include <systemc>

using namespace sc_core;

template <class T>
class Fork : public sc_module {
  public:
    sc_fifo_in<T> input;
    sc_fifo_out<T> output1;
    sc_fifo_out<T> output2;

    SC_HAS_PROCESS(Fork);

    Fork(sc_module_name name) : sc_module(name) {
      SC_THREAD(process);
    }

    void process() {
      while(1) {
        T value = input.read();
        output1.write(value);
        output2.write(value);
      }
    }
};

#endif /* _FORK_H_ */

