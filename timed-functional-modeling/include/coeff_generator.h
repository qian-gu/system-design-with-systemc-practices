#ifndef _COEFF_GENERATOR_H_
#define _COEFF_GENERATOR_H_

#include <systemc>

using namespace sc_core;

template <class T>
class CoeffGenerator : public sc_module {
  public:
    sc_out<T> output;

    SC_HAS_PROCESS(CoeffGenerator);

    CoeffGenerator(sc_module_name name, const T & initial, unsigned iter_num) :
      sc_module(name), coefficient_(initial), iter_num_(iter_num) {
      SC_THREAD(process);
    }

    void process() {
      for(unsigned i = 0; i < iter_num_; i++) {
        output.write(coefficient_++);
        wait(SC_ZERO_TIME);
      }
    }

  private:
    T coefficient_;
    unsigned iter_num_;
};

#endif /* _COEFF_GENERATOR_H_ */

