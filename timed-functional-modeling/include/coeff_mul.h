#ifndef _COEFF_MUL_H_
#define _COEFF_MUL_H_

#include <systemc>

using namespace sc_core;

template <class T>
class CoeffMul : public sc_module {
  public:
    sc_in<T> coefficient;
    sc_fifo_in<T> input;
    sc_fifo_out<T> output;

    SC_HAS_PROCESS(CoeffMul);

    CoeffMul(sc_module_name name) : sc_module(name) {
      SC_THREAD(process);
    }

    void process() {
      while(1) {
        output.write(input.read() * coefficient.read());
      }
    }
};

#endif /* _COEFF_MUL_H_ */

