#include "adder.h"
#include "const_generator.h"
#include "fork.h"
#include "printer.h"

#include <systemc>

using namespace sc_core;

int sc_main(int argc, char **argv)
{
  // Module instances
  ConstGenerator<int> const_generaor("const_generaor", 1);
  Adder<int> adder("adder");
  Fork<int> fork("fork");
  Printer<int> printer("printer", 10);
  // FIFOs
  sc_fifo<int> const_out("const_out", 5);
  sc_fifo<int> mul_out("mul_out", 1);
  sc_fifo<int> adder_out("adder_out", 1);
  sc_fifo<int> feedback("feedback", 1);
  sc_fifo<int> to_printer("to_printer", 1);

  // System would deadlock without this initial value, as the adder would never
  // be able to successfully read from its first input.
  feedback.write(42);

  // Interconnet
  const_generaor.output(const_out);
  adder.input1(const_out);
  adder.input2(feedback);
  adder.output(adder_out);
  fork.input(adder_out);
  fork.output1(feedback);
  fork.output2(to_printer);
  printer.input(to_printer);

  // Start simulation without time limit
  //sc_start();
  sc_start(100, SC_SEC);
  return 0;
}
