#include "camelApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
camelApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

camelApp::camelApp(InputParameters parameters) : MooseApp(parameters)
{
  camelApp::registerAll(_factory, _action_factory, _syntax);
}

camelApp::~camelApp() {}

void
camelApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"camelApp"});
  Registry::registerActionsTo(af, {"camelApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
camelApp::registerApps()
{
  registerApp(camelApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
camelApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  camelApp::registerAll(f, af, s);
}
extern "C" void
camelApp__registerApps()
{
  camelApp::registerApps();
}
