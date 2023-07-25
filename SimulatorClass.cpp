/*----- PROTECTED REGION ID(SimulatorClass.cpp) ENABLED START -----*/
static const char *RcsId      = "$Id:  $";
static const char *TagName    = "$Name:  $";
static const char *CvsPath    = "$Source:  $";
static const char *SvnPath    = "$HeadURL:  $";
static const char *HttpServer = "http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/";
//=============================================================================
//
// file :        SimulatorClass.cpp
//
// description : C++ source for the SimulatorClass. A singleton
//               class derived from DeviceClass. It implements the
//               command list and all properties and methods required
//               by the �name� once per process.
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


#include <tango.h>
#include <Simulator.h>
#include <SimulatorClass.h>

/*----- PROTECTED REGION END -----*/	//	SimulatorClass.cpp

//-------------------------------------------------------------------
/**
 *	Create SimulatorClass singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_Simulator_class(const char *name) {
		return Simulator_ns::SimulatorClass::init(name);
	}
}

namespace Simulator_ns
{
//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
SimulatorClass *SimulatorClass::_instance = NULL;

//--------------------------------------------------------
/**
 * method : 		SimulatorClass::SimulatorClass(string &s)
 * description : 	constructor for the SimulatorClass
 *
 * @param s	The class name
 */
//--------------------------------------------------------
SimulatorClass::SimulatorClass(string &s):Tango::DeviceClass(s)
{
	cout2 << "Entering SimulatorClass constructor" << endl;
	set_default_property();
	write_class_property();

	/*----- PROTECTED REGION ID(SimulatorClass::constructor) ENABLED START -----*/
	

	/*----- PROTECTED REGION END -----*/	//	SimulatorClass::constructor

	cout2 << "Leaving SimulatorClass constructor" << endl;
}

//--------------------------------------------------------
/**
 * method : 		SimulatorClass::~SimulatorClass()
 * description : 	destructor for the SimulatorClass
 */
//--------------------------------------------------------
SimulatorClass::~SimulatorClass()
{
	/*----- PROTECTED REGION ID(SimulatorClass::destructor) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	SimulatorClass::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		SimulatorClass::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
SimulatorClass *SimulatorClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new SimulatorClass(s);
		}
		catch (bad_alloc &)
		{
			throw;
		}
	}
	return _instance;
}

//--------------------------------------------------------
/**
 * method : 		SimulatorClass::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
SimulatorClass *SimulatorClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}



//===================================================================
//	Command execution method calls
//===================================================================
//--------------------------------------------------------
/**
 * method : 		UpdateAttributesClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *UpdateAttributesClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "UpdateAttributesClass::execute(): arrived" << endl;
	return insert((static_cast<Simulator *>(device))->update_attributes());
}


//===================================================================
//	Properties management
//===================================================================
//--------------------------------------------------------
/**
 *	Method      : SimulatorClass::get_class_property()
 *	Description : Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum SimulatorClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : SimulatorClass::get_default_device_property()
 *	Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum SimulatorClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : SimulatorClass::get_default_class_property()
 *	Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum SimulatorClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : SimulatorClass::set_default_property()
 *	Description : Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void SimulatorClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;
	vector<string>	vect_data;

	//	Set Default Class Properties

	//	Set Default device Properties
	prop_name = "DeviceNr";
	prop_desc = "This is the device_nr you wish to read. 1 ramp,2 rampx2, 3 error or 4 timeout";
	prop_def  = "1";
	vect_data.clear();
	vect_data.push_back("1");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
}

//--------------------------------------------------------
/**
 *	Method      : SimulatorClass::write_class_property()
 *	Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void SimulatorClass::write_class_property()
{
	//	First time, check if database used
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("simulator generator");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("Generates waves to simulator tango. Can be used for calibration and regression testing.");
	description << str_desc;
	data.push_back(description);

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("TANGO_BASE_CLASS");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	get_db_class()->put_property(data);
}

//===================================================================
//	Factory methods
//===================================================================

//--------------------------------------------------------
/**
 *	Method      : SimulatorClass::device_factory()
 *	Description : Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void SimulatorClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
	/*----- PROTECTED REGION ID(SimulatorClass::device_factory_before) ENABLED START -----*/

	//	Add your own code
	

	/*----- PROTECTED REGION END -----*/	//	SimulatorClass::device_factory_before

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
		device_list.push_back(new Simulator(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		Simulator *dev = static_cast<Simulator *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	/*----- PROTECTED REGION ID(SimulatorClass::device_factory_after) ENABLED START -----*/

	//	Add your own code
	

	/*----- PROTECTED REGION END -----*/	//	SimulatorClass::device_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : SimulatorClass::attribute_factory()
 *	Description : Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void SimulatorClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(SimulatorClass::attribute_factory_before) ENABLED START -----*/

	//	Add your own code

	/*----- PROTECTED REGION END -----*/	//	SimulatorClass::attribute_factory_before
	//	Attribute : Amplitude
	AmplitudeAttrib	*amplitude = new AmplitudeAttrib();
	Tango::UserDefaultAttrProp	amplitude_prop;
	amplitude_prop.set_description("vertical axis (range 0..Height)");
	amplitude_prop.set_label("Amplitude");
	//	unit	not set for Amplitude
	//	standard_unit	not set for Amplitude
	//	display_unit	not set for Amplitude
	//	format	not set for Amplitude
	//	max_value	not set for Amplitude
	//	min_value	not set for Amplitude
	amplitude_prop.set_max_alarm("2");
	amplitude_prop.set_min_alarm("0");
	amplitude_prop.set_max_warning("1");
	amplitude_prop.set_min_warning("0");
	//	delta_t	not set for Amplitude
	//	delta_val	not set for Amplitude
	
	amplitude->set_default_properties(amplitude_prop);
	//	Not Polled
	amplitude->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(amplitude);

	//	Attribute : smsstring
	smsstringAttrib	*smsstring = new smsstringAttrib();
	Tango::UserDefaultAttrProp	smsstring_prop;
	smsstring_prop.set_description("sms string for ego");
	//	label	not set for smsstring
	//	unit	not set for smsstring
	//	standard_unit	not set for smsstring
	//	display_unit	not set for smsstring
	//	format	not set for smsstring
	//	max_value	not set for smsstring
	//	min_value	not set for smsstring
	//	max_alarm	not set for smsstring
	//	min_alarm	not set for smsstring
	//	max_warning	not set for smsstring
	//	min_warning	not set for smsstring
	//	delta_t	not set for smsstring
	//	delta_val	not set for smsstring
	
	smsstring->set_default_properties(smsstring_prop);
	//	Not Polled
	smsstring->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(smsstring);


	//	Create a list of static attributes
	create_static_attribute_list(get_class_attr()->get_attr_list());
	/*----- PROTECTED REGION ID(SimulatorClass::attribute_factory_after) ENABLED START -----*/

	//	Add your own code

	/*----- PROTECTED REGION END -----*/	//	SimulatorClass::attribute_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : SimulatorClass::pipe_factory()
 *	Description : Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void SimulatorClass::pipe_factory()
{
	/*----- PROTECTED REGION ID(SimulatorClass::pipe_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	SimulatorClass::pipe_factory_before
	/*----- PROTECTED REGION ID(SimulatorClass::pipe_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	SimulatorClass::pipe_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : SimulatorClass::command_factory()
 *	Description : Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void SimulatorClass::command_factory()
{
	/*----- PROTECTED REGION ID(SimulatorClass::command_factory_before) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	SimulatorClass::command_factory_before


	//	Command UpdateAttributes
	UpdateAttributesClass	*pUpdateAttributesCmd =
		new UpdateAttributesClass("UpdateAttributes",
			Tango::DEV_VOID, Tango::DEV_STRING,
			"",
			"A string with all values returned type, height, x ,y",
			Tango::OPERATOR);
	command_list.push_back(pUpdateAttributesCmd);

	/*----- PROTECTED REGION ID(SimulatorClass::command_factory_after) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	SimulatorClass::command_factory_after
}

//===================================================================
//	Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method : 		SimulatorClass::create_static_attribute_list
 * description : 	Create the a list of static attributes
 *
 * @param	att_list	the ceated attribute list
 */
//--------------------------------------------------------
void SimulatorClass::create_static_attribute_list(vector<Tango::Attr *> &att_list)
{
	for (unsigned long i=0 ; i<att_list.size() ; i++)
	{
		string att_name(att_list[i]->get_name());
		transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
		defaultAttList.push_back(att_name);
	}

	cout2 << defaultAttList.size() << " attributes in default list" << endl;

	/*----- PROTECTED REGION ID(SimulatorClass::create_static_att_list) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	SimulatorClass::create_static_att_list
}


//--------------------------------------------------------
/**
 * method : 		SimulatorClass::erase_dynamic_attributes
 * description : 	delete the dynamic attributes if any.
 *
 * @param	devlist_ptr	the device list pointer
 * @param	list of all attributes
 */
//--------------------------------------------------------
void SimulatorClass::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, vector<Tango::Attr *> &att_list)
{
	Tango::Util *tg = Tango::Util::instance();

	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((string)(*devlist_ptr)[i]).c_str());
		Simulator *dev = static_cast<Simulator *> (dev_impl);

		vector<Tango::Attribute *> &dev_att_list = dev->get_device_attr()->get_attribute_list();
		vector<Tango::Attribute *>::iterator ite_att;
		for (ite_att=dev_att_list.begin() ; ite_att != dev_att_list.end() ; ++ite_att)
		{
			string att_name((*ite_att)->get_name_lower());
			if ((att_name == "state") || (att_name == "status"))
				continue;
			vector<string>::iterator ite_str = find(defaultAttList.begin(), defaultAttList.end(), att_name);
			if (ite_str == defaultAttList.end())
			{
				cout2 << att_name << " is a UNWANTED dynamic attribute for device " << (*devlist_ptr)[i] << endl;
				Tango::Attribute &att = dev->get_device_attr()->get_attr_by_name(att_name.c_str());
				dev->remove_attribute(att_list[att.get_attr_idx()], true, false);
				--ite_att;
			}
		}
	}
	/*----- PROTECTED REGION ID(SimulatorClass::erase_dynamic_attributes) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	SimulatorClass::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Method      : SimulatorClass::get_attr_by_name()
 *	Description : returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *SimulatorClass::get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname)
{
	vector<Tango::Attr *>::iterator it;
	for (it=att_list.begin() ; it<att_list.end() ; ++it)
		if ((*it)->get_name()==attname)
			return (*it);
	//	Attr does not exist
	return NULL;
}


/*----- PROTECTED REGION ID(SimulatorClass::Additional Methods) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	SimulatorClass::Additional Methods
} //	namespace