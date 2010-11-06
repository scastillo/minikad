//
// Generated file, do not edit! Created by opp_msgc 4.1 from streamResponse.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "streamResponse_m.h"

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




Register_Class(StreamResponse);

StreamResponse::StreamResponse(const char *name, int kind) : cMessage(name,kind)
{
    this->provider_var = 0;
    this->dest_var = 0;
    this->stream_var = 0;
}

StreamResponse::StreamResponse(const StreamResponse& other) : cMessage()
{
    setName(other.getName());
    operator=(other);
}

StreamResponse::~StreamResponse()
{
}

StreamResponse& StreamResponse::operator=(const StreamResponse& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    this->provider_var = other.provider_var;
    this->dest_var = other.dest_var;
    this->stream_var = other.stream_var;
    return *this;
}

void StreamResponse::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->provider_var);
    doPacking(b,this->dest_var);
    doPacking(b,this->stream_var);
}

void StreamResponse::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->provider_var);
    doUnpacking(b,this->dest_var);
    doUnpacking(b,this->stream_var);
}

int StreamResponse::getProvider() const
{
    return provider_var;
}

void StreamResponse::setProvider(int provider_var)
{
    this->provider_var = provider_var;
}

int StreamResponse::getDest() const
{
    return dest_var;
}

void StreamResponse::setDest(int dest_var)
{
    this->dest_var = dest_var;
}

int StreamResponse::getStream() const
{
    return stream_var;
}

void StreamResponse::setStream(int stream_var)
{
    this->stream_var = stream_var;
}

class StreamResponseDescriptor : public cClassDescriptor
{
  public:
    StreamResponseDescriptor();
    virtual ~StreamResponseDescriptor();

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

Register_ClassDescriptor(StreamResponseDescriptor);

StreamResponseDescriptor::StreamResponseDescriptor() : cClassDescriptor("StreamResponse", "cMessage")
{
}

StreamResponseDescriptor::~StreamResponseDescriptor()
{
}

bool StreamResponseDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<StreamResponse *>(obj)!=NULL;
}

const char *StreamResponseDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int StreamResponseDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int StreamResponseDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *StreamResponseDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "provider",
        "dest",
        "stream",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int StreamResponseDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "provider")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dest")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "stream")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *StreamResponseDescriptor::getFieldTypeString(void *object, int field) const
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

const char *StreamResponseDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int StreamResponseDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    StreamResponse *pp = (StreamResponse *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string StreamResponseDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    StreamResponse *pp = (StreamResponse *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getProvider());
        case 1: return long2string(pp->getDest());
        case 2: return long2string(pp->getStream());
        default: return "";
    }
}

bool StreamResponseDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    StreamResponse *pp = (StreamResponse *)object; (void)pp;
    switch (field) {
        case 0: pp->setProvider(string2long(value)); return true;
        case 1: pp->setDest(string2long(value)); return true;
        case 2: pp->setStream(string2long(value)); return true;
        default: return false;
    }
}

const char *StreamResponseDescriptor::getFieldStructName(void *object, int field) const
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

void *StreamResponseDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    StreamResponse *pp = (StreamResponse *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


