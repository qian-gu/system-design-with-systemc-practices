#ifndef _ADDER_H_
#define _ADDER_H_

#include <systemc>

using namespace sc_core;

template <class T>
class Adder : public sc_module {
  public:
    sc_fifo_in<T> input1;
    sc_fifo_in<T> input2;
    sc_fifo_out<T> output;

    SC_HAS_PROCESS(Adder);

    Adder(sc_module_name name) : sc_module(name) {
      SC_THREAD(process);
    }

    void process() {
      while(1) {
        output.write(input1.read() + input2.read());
      }
    }
};

#endif /* _ADDER_H_ */
