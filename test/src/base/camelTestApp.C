//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "camelTestApp.h"
#include "camelApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
camelTestApp::validParams()
{
  InputParameters params = camelApp::validParams();
  return params;
}

camelTestApp::camelTestApp(InputParameters parameters) : MooseApp(parameters)
{
  camelTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

camelTestApp::~camelTestApp() {}

void
camelTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  camelApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"camelTestApp"});
    Registry::registerActionsTo(af, {"camelTestApp"});
  }
}

void
camelTestApp::registerApps()
{
  registerApp(camelApp);
  registerApp(camelTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
camelTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  camelTestApp::registerAll(f, af, s);
}
extern "C" void
camelTestApp__registerApps()
{
  camelTestApp::registerApps();
}
