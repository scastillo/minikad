//
// Generated file, do not edit! Created by opp_msgc 4.1 from streamRegReq.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "streamRegReq_m.h"

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




Register_Class(StreamRegReq);

StreamRegReq::StreamRegReq(const char *name, int kind) : cPacket(name,kind)
{
    this->stream_var = 0;
    this->dest_var = 0;
    this->source_var = 0;
    this->extra_var = 0;
    this->fromSP_var = 0;
}

StreamRegReq::StreamRegReq(const StreamRegReq& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

StreamRegReq::~StreamRegReq()
{
}

StreamRegReq& StreamRegReq::operator=(const StreamRegReq& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->stream_var = other.stream_var;
    this->dest_var = other.dest_var;
    this->source_var = other.source_var;
    this->extra_var = other.extra_var;
    this->fromSP_var = other.fromSP_var;
    return *this;
}

void StreamRegReq::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->stream_var);
    doPacking(b,this->dest_var);
    doPacking(b,this->source_var);
    doPacking(b,this->extra_var);
    doPacking(b,this->fromSP_var);
}

void StreamRegReq::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->stream_var);
    doUnpacking(b,this->dest_var);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->extra_var);
    doUnpacking(b,this->fromSP_var);
}

int StreamRegReq::getStream() const
{
    return stream_var;
}

void StreamRegReq::setStream(int stream_var)
{
    this->stream_var = stream_var;
}

int StreamRegReq::getDest() const
{
    return dest_var;
}

void StreamRegReq::setDest(int dest_var)
{
    this->dest_var = dest_var;
}

int StreamRegReq::getSource() const
{
    return source_var;
}

void StreamRegReq::setSource(int source_var)
{
    this->source_var = source_var;
}

int StreamRegReq::getExtra() const
{
    return extra_var;
}

void StreamRegReq::setExtra(int extra_var)
{
    this->extra_var = extra_var;
}

bool StreamRegReq::getFromSP() const
{
    return fromSP_var;
}

void StreamRegReq::setFromSP(bool fromSP_var)
{
    this->fromSP_var = fromSP_var;
}

class StreamRegReqDescriptor : public cClassDescriptor
{
  public:
    StreamRegReqDescriptor();
    virtual ~StreamRegReqDescriptor();

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

Register_ClassDescriptor(StreamRegReqDescriptor);

StreamRegReqDescriptor::StreamRegReqDescriptor() : cClassDescriptor("StreamRegReq", "cPacket")
{
}

StreamRegReqDescriptor::~StreamRegReqDescriptor()
{
}

bool StreamRegReqDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<StreamRegReq *>(obj)!=NULL;
}

const char *StreamRegReqDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int StreamRegReqDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int StreamRegReqDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *StreamRegReqDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "stream",
        "dest",
        "source",
        "extra",
        "fromSP",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int StreamRegReqDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "stream")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dest")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "extra")==0) return base+3;
    if (fieldName[0]=='f' && strcmp(fieldName, "fromSP")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *StreamRegReqDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
        "bool",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *StreamRegReqDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int StreamRegReqDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    StreamRegReq *pp = (StreamRegReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string StreamRegReqDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    StreamRegReq *pp = (StreamRegReq *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getStream());
        case 1: return long2string(pp->getDest());
        case 2: return long2string(pp->getSource());
        case 3: return long2string(pp->getExtra());
        case 4: return bool2string(pp->getFromSP());
        default: return "";
    }
}

bool StreamRegReqDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    StreamRegReq *pp = (StreamRegReq *)object; (void)pp;
    switch (field) {
        case 0: pp->setStream(string2long(value)); return true;
        case 1: pp->setDest(string2long(value)); return true;
        case 2: pp->setSource(string2long(value)); return true;
        case 3: pp->setExtra(string2long(value)); return true;
        case 4: pp->setFromSP(string2bool(value)); return true;
        default: return false;
    }
}

const char *StreamRegReqDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        NULL,
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *StreamRegReqDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    StreamRegReq *pp = (StreamRegReq *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


