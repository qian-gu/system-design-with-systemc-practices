#ifndef _CONST_GENERATOR_H_
#define _CONST_GENERATOR_H_

#include <systemc>

using namespace sc_core;

template <class T>
class ConstGenerator : public sc_module {
  public:
    sc_fifo_out<T> output;

    SC_HAS_PROCESS(ConstGenerator);

    ConstGenerator(sc_module_name name, const T & constant) : sc_module(name), constant_(constant) {
      SC_THREAD(process);
    }

    void process() {
      while(1) {
        output.write(constant_);
      }
    }

  private:
    T constant_;
};

#endif /* _CONST_GENERATOR_H_ */
