/* Travelling Salesman Project
 * ACMS 60212
 * Writer.hpp
 * class will have functionality to write output files for visuals in R
 */

#ifndef WRITER_HPP
#define WRITER_HPP

#include <cassert>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <list>

#include "Node.hpp"

class Writer {
 
   public:
      Writer();
      Writer(const std::string&);
      void writePath(std::list<Node>&,std::list<double>&);

   private:
      std::ofstream fp;
};

Writer::Writer() {};

// non-default constructor will take a file name and read it
Writer::Writer(const std::string &filename) {

   fp.open(filename);
   assert(fp);
}

void Writer::writePath(std::list<Node>& path, std::list<double>& weights) {

   auto path_it = path.begin();
   auto weights_it = weights.begin();
   while (path_it != path.end()) {
      fp << path_it->getName() << ", " << path_it->getState() << '\t' << path_it->getLat() << '\t' << path_it->getLon() << '\t';
      if (weights_it++ == weights.begin()) {
         fp << 0 << '\n';
      } else {
         fp << *(weights_it++) << '\n';
      }
      ++path_it;
   }
}

#endif
