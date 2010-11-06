//
// Generated file, do not edit! Created by opp_msgc 4.1 from flowRegReq.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "flowRegReq_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(FlowRegReq);

FlowRegReq::FlowRegReq(const char *name, int kind) : cPacket(name,kind)
{
    this->flow_var = 0;
    this->dest_var = 0;
    this->source_var = 0;
}

FlowRegReq::FlowRegReq(const FlowRegReq& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

FlowRegReq::~FlowRegReq()
{
}

FlowRegReq& FlowRegReq::operator=(const FlowRegReq& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->flow_var = other.flow_var;
    this->dest_var = other.dest_var;
    this->source_var = other.source_var;
    return *this;
}

void FlowRegReq::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->flow_var);
    doPacking(b,this->dest_var);
    doPacking(b,this->source_var);
}

void FlowRegReq::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->flow_var);
    doUnpacking(b,this->dest_var);
    doUnpacking(b,this->source_var);
}

int FlowRegReq::getFlow() const
{
    return flow_var;
}

void FlowRegReq::setFlow(int flow_var)
{
    this->flow_var = flow_var;
}

int FlowRegReq::getDest() const
{
    return dest_var;
}

void FlowRegReq::setDest(int dest_var)
{
    this->dest_var = dest_var;
}

int FlowRegReq::getSource() const
{
    return source_var;
}

void FlowRegReq::setSource(int source_var)
{
    this->source_var = source_var;
}

class FlowRegReqDescriptor : public cClassDescriptor
{
  public:
    FlowRegReqDescriptor();
    virtual ~FlowRegReqDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(FlowRegReqDescriptor);

FlowRegReqDescriptor::FlowRegReqDescriptor() : cClassDescriptor("FlowRegReq", "cPacket")
{
}

FlowRegReqDescriptor::~FlowRegReqDescriptor()
{
}

bool FlowRegReqDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<FlowRegReq *>(obj)!=NULL;
}

const char *FlowRegReqDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int FlowRegReqDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int FlowRegReqDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *FlowRegReqDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "flow",
        "dest",
        "source",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int FlowRegReqDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flow")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dest")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *FlowRegReqDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *FlowRegReqDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int FlowRegReqDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    FlowRegReq *pp = (FlowRegReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string FlowRegReqDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    FlowRegReq *pp = (FlowRegReq *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getFlow());
        case 1: return long2string(pp->getDest());
        case 2: return long2string(pp->getSource());
        default: return "";
    }
}

bool FlowRegReqDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    FlowRegReq *pp = (FlowRegReq *)object; (void)pp;
    switch (field) {
        case 0: pp->setFlow(string2long(value)); return true;
        case 1: pp->setDest(string2long(value)); return true;
        case 2: pp->setSource(string2long(value)); return true;
        default: return false;
    }
}

const char *FlowRegReqDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *FlowRegReqDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    FlowRegReq *pp = (FlowRegReq *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


