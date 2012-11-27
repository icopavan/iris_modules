/**
 * \file components/gpp/phy/Example/ExampleComponent.h
 * \version 1.0
 *
 * \section COPYRIGHT
 *
 * Copyright 2012 The Iris Project Developers. See the
 * COPYRIGHT file at the top-level directory of this distribution
 * and at http://www.softwareradiosystems.com/iris/copyright.html.
 *
 * \section LICENSE
 *
 * This file is part of the Iris Project.
 *
 * Iris is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 * 
 * Iris is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * A copy of the GNU Lesser General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 * \section DESCRIPTION
 *
 * An example PhyComponent to be used as a template for new PhyComponents.
 */

#ifndef PHY_EXAMPLECOMPONENT_H_
#define PHY_EXAMPLECOMPONENT_H_

#include "irisapi/PhyComponent.h"

namespace iris
{
namespace phy
{

/** An example PhyComponent to be used as a template for new PhyComponents.
 *
 * Copy this component, rename folder, .h and .cpp files.
 * Edit all files for your new component and build.
 */
class ExampleComponent
  : public PhyComponent
{
 public:
	/** Construct this component.
	 *
	 * Call the constructor on PhyComponent and pass in all details
	 * about the component.	Register all parameters and events.
	 * \param name the name given to this component in the radio config
	 */
  ExampleComponent(std::string name);

  /** Calculate the output types generated by this component.
   *
	 * Given the data-types associated with each input port, provide
	 * the data-types which will be produced on each output port.
	 * \param inputTypes  The map of input port names and data-type identifiers
	 * \param outputTypes Map of output port names and data-type identifiers
	 */
  virtual void calculateOutputTypes(
      const std::map<std::string, int>& inputTypes,
      std::map<std::string, int>& outputTypes);

  /** Register the ports of this component.
   *
	 * Register ports by name, declare them as input or output and
	 * provide a list of valid data types.
	 */
  virtual void registerPorts();

	/// Do any initialization required by this component.
  virtual void initialize();

  /** Process input data and generate output data
   *
	 * This is where the work of this component gets done.
	 * Typically components will take DataSets from their input
	 * ports, process them and write DataSets to their output ports.
	 */
  virtual void process();

 private:

   /// Example of a parameter which will be exposed by this component
   uint32_t example_x;
};

} // namespace phy
} // namespace iris

#endif // PHY_EXAMPLECOMPONENT_H_
