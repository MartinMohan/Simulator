/*----- PROTECTED REGION ID(SimulatorClass.h) ENABLED START -----*/
//=============================================================================
//
// file :        SimulatorClass.h
//
// description : Include for the SimulatorClass root class.
//               This class is the singleton class for.
//               the Simulator device class..
//               It contains all properties and methods which the .
//               Simulator requires only once e.g. the commands.
//
// project :     simulator generator.
//
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// SVN only:
// $HeadURL:  $
//
// CVS only:
// $Source:  $
// $Log:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef BENCHMARKCLASS_H
#define BENCHMARKCLASS_H

#include <tango.h>
#include <Simulator.h>

/*----- PROTECTED REGION END -----*/	//	SimulatorClass.h


namespace Simulator_ns
{
/*----- PROTECTED REGION ID(SimulatorClass::classes for dynamic creation) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	SimulatorClass::classes for dynamic creation

//=========================================
//	Define classes for attributes
//=========================================
//	Attribute Amplitude class definition
class AmplitudeAttrib: public Tango::Attr
{
public:
	AmplitudeAttrib():Attr("Amplitude",
			Tango::DEV_FLOAT, Tango::READ) {};
	~AmplitudeAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<Simulator *>(dev))->read_Amplitude(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<Simulator *>(dev))->is_Amplitude_allowed(ty);}
};

//	Attribute smsstring class definition
class smsstringAttrib: public Tango::Attr
{
public:
	smsstringAttrib():Attr("smsstring",
			Tango::DEV_STRING, Tango::READ) {};
	~smsstringAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<Simulator *>(dev))->read_smsstring(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<Simulator *>(dev))->is_smsstring_allowed(ty);}
};


//=========================================
//	Define classes for commands
//=========================================
//	Command UpdateAttributes class definition
class UpdateAttributesClass : public Tango::Command
{
public:
	UpdateAttributesClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	UpdateAttributesClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~UpdateAttributesClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Simulator *>(dev))->is_UpdateAttributes_allowed(any);}
};


/**
 *	The SimulatorClass singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  SimulatorClass : public Tango::DeviceClass
#else
class SimulatorClass : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(SimulatorClass::Additionnal DServer data members) ENABLED START -----*/
public:
	

	/*----- PROTECTED REGION END -----*/	//	SimulatorClass::Additionnal DServer data members

	public:
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
	
		//	Method prototypes
		static SimulatorClass *init(const char *);
		static SimulatorClass *instance();
		~SimulatorClass();
		Tango::DbDatum	get_class_property(string &);
		Tango::DbDatum	get_default_device_property(string &);
		Tango::DbDatum	get_default_class_property(string &);
	
	protected:
		SimulatorClass(string &);
		static SimulatorClass *_instance;
		void command_factory();
		void attribute_factory(vector<Tango::Attr *> &);
		void pipe_factory();
		void write_class_property();
		void set_default_property();
		void get_class_property();
		string get_cvstag();
		string get_cvsroot();
	
	private:
		void device_factory(const Tango::DevVarStringArray *);
		void create_static_attribute_list(vector<Tango::Attr *> &);
		void erase_dynamic_attributes(const Tango::DevVarStringArray *,vector<Tango::Attr *> &);
		vector<string>	defaultAttList;
		Tango::Attr *get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname);
};

}	//	End of namespace

#endif   //	Simulator_H
