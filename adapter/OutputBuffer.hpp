/**********************************************************************************************
 *                                                                                            *
 *       CalculiX adapter for heat transfer coupling and mechanical FSI using preCICE         *
 *       Heat transfer adapter developed by Lucía Cheung with the support of SimScale GmbH    *
 *                                                                                            *
 *       Adapter extended to fluid-structure interaction by Alexander Rusch                   *
 *                                                                                            *
 *********************************************************************************************/

#ifndef CCX_OUTPUT_BUFFER_HPP
#define CCX_OUTPUT_BUFFER_HPP

extern "C" {

#include "OutputBuffer.h"
}

#include <map>
#include <string>
#include <vector>

struct State {
  std::map<std::string, std::vector<double>> data_double;
  std::map<std::string, std::vector<ITG>>    data_itg;
};

class outputBuffer {
public:
  std::vector<State> states;

  void clear();
  void writeNewStep();
  void startRead();
  bool readNext();

  double  *getDoubleData(const std::string &name);
  ITG     *getITGData(const std::string &name);
  unsigned getDoubleDataSize(const std::string &name);
  unsigned getITGDataSize(const std::string &name);

  void writeDoubleData(const std::string &name, double *data, unsigned n);
  void writeITGData(const std::string &name, ITG *data, unsigned n);

private:
  unsigned currentReadIter{0};
};

#endif