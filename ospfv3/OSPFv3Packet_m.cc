//
// Generated file, do not edit! Created by nedtool 5.0 from ansa/routing/ospfv3/OSPFv3Packet.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "OSPFv3Packet_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: no doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: no doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::OSPFv3PacketType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::OSPFv3PacketType"));
    e->insert(HELLO_PACKET, "HELLO_PACKET");
    e->insert(DATABASE_DESCRIPTION, "DATABASE_DESCRIPTION");
    e->insert(LSR, "LSR");
    e->insert(LSU, "LSU");
    e->insert(LS_ACK, "LS_ACK");
);

Register_Class(OSPFv3Packet);

OSPFv3Packet::OSPFv3Packet(const char *name, int kind) : ::omnetpp::cPacket(name,kind)
{
    this->version = 3;
    this->type = 0;
    this->packetLength = 0;
    this->checksum = 0;
    this->instanceID = 0;
}

OSPFv3Packet::OSPFv3Packet(const OSPFv3Packet& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

OSPFv3Packet::~OSPFv3Packet()
{
}

OSPFv3Packet& OSPFv3Packet::operator=(const OSPFv3Packet& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3Packet::copy(const OSPFv3Packet& other)
{
    this->version = other.version;
    this->type = other.type;
    this->packetLength = other.packetLength;
    this->routerID = other.routerID;
    this->areaID = other.areaID;
    this->checksum = other.checksum;
    this->instanceID = other.instanceID;
}

void OSPFv3Packet::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->version);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->packetLength);
    doParsimPacking(b,this->routerID);
    doParsimPacking(b,this->areaID);
    doParsimPacking(b,this->checksum);
    doParsimPacking(b,this->instanceID);
}

void OSPFv3Packet::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->version);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->packetLength);
    doParsimUnpacking(b,this->routerID);
    doParsimUnpacking(b,this->areaID);
    doParsimUnpacking(b,this->checksum);
    doParsimUnpacking(b,this->instanceID);
}

uint8_t OSPFv3Packet::getVersion() const
{
    return this->version;
}

void OSPFv3Packet::setVersion(uint8_t version)
{
    this->version = version;
}

uint8_t OSPFv3Packet::getType() const
{
    return this->type;
}

void OSPFv3Packet::setType(uint8_t type)
{
    this->type = type;
}

uint16_t OSPFv3Packet::getPacketLength() const
{
    return this->packetLength;
}

void OSPFv3Packet::setPacketLength(uint16_t packetLength)
{
    this->packetLength = packetLength;
}

IPv4Address& OSPFv3Packet::getRouterID()
{
    return this->routerID;
}

void OSPFv3Packet::setRouterID(const IPv4Address& routerID)
{
    this->routerID = routerID;
}

IPv4Address& OSPFv3Packet::getAreaID()
{
    return this->areaID;
}

void OSPFv3Packet::setAreaID(const IPv4Address& areaID)
{
    this->areaID = areaID;
}

uint16_t OSPFv3Packet::getChecksum() const
{
    return this->checksum;
}

void OSPFv3Packet::setChecksum(uint16_t checksum)
{
    this->checksum = checksum;
}

uint8_t OSPFv3Packet::getInstanceID() const
{
    return this->instanceID;
}

void OSPFv3Packet::setInstanceID(uint8_t instanceID)
{
    this->instanceID = instanceID;
}

class OSPFv3PacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3PacketDescriptor();
    virtual ~OSPFv3PacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3PacketDescriptor);

OSPFv3PacketDescriptor::OSPFv3PacketDescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3Packet", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

OSPFv3PacketDescriptor::~OSPFv3PacketDescriptor()
{
    delete[] propertynames;
}

bool OSPFv3PacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3Packet *>(obj)!=nullptr;
}

const char **OSPFv3PacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3PacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3PacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int OSPFv3PacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3PacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "version",
        "type",
        "packetLength",
        "routerID",
        "areaID",
        "checksum",
        "instanceID",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int OSPFv3PacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "version")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetLength")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "routerID")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "areaID")==0) return base+4;
    if (fieldName[0]=='c' && strcmp(fieldName, "checksum")==0) return base+5;
    if (fieldName[0]=='i' && strcmp(fieldName, "instanceID")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3PacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
        "uint8_t",
        "uint16_t",
        "IPv4Address",
        "IPv4Address",
        "uint16_t",
        "uint8_t",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3PacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3PacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3PacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3Packet *pp = (OSPFv3Packet *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OSPFv3PacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3Packet *pp = (OSPFv3Packet *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getVersion());
        case 1: return ulong2string(pp->getType());
        case 2: return ulong2string(pp->getPacketLength());
        case 3: {std::stringstream out; out << pp->getRouterID(); return out.str();}
        case 4: {std::stringstream out; out << pp->getAreaID(); return out.str();}
        case 5: return ulong2string(pp->getChecksum());
        case 6: return ulong2string(pp->getInstanceID());
        default: return "";
    }
}

bool OSPFv3PacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3Packet *pp = (OSPFv3Packet *)object; (void)pp;
    switch (field) {
        case 0: pp->setVersion(string2ulong(value)); return true;
        case 1: pp->setType(string2ulong(value)); return true;
        case 2: pp->setPacketLength(string2ulong(value)); return true;
        case 5: pp->setChecksum(string2ulong(value)); return true;
        case 6: pp->setInstanceID(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFv3PacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: return omnetpp::opp_typename(typeid(IPv4Address));
        case 4: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *OSPFv3PacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3Packet *pp = (OSPFv3Packet *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getRouterID()); break;
        case 4: return (void *)(&pp->getAreaID()); break;
        default: return nullptr;
    }
}

OSPFv3Options::OSPFv3Options()
{
    this->reservedOne = false;
    this->reservedTwo = false;
    this->dcBit = false;
    this->rBit = false;
    this->nBit = false;
    this->xBit = 0;
    this->eBit = false;
    this->v6Bit = false;
}

void __doPacking(omnetpp::cCommBuffer *b, const OSPFv3Options& a)
{
    doParsimPacking(b,a.reservedOne);
    doParsimPacking(b,a.reservedTwo);
    doParsimPacking(b,a.dcBit);
    doParsimPacking(b,a.rBit);
    doParsimPacking(b,a.nBit);
    doParsimPacking(b,a.xBit);
    doParsimPacking(b,a.eBit);
    doParsimPacking(b,a.v6Bit);
}

void __doUnpacking(omnetpp::cCommBuffer *b, OSPFv3Options& a)
{
    doParsimUnpacking(b,a.reservedOne);
    doParsimUnpacking(b,a.reservedTwo);
    doParsimUnpacking(b,a.dcBit);
    doParsimUnpacking(b,a.rBit);
    doParsimUnpacking(b,a.nBit);
    doParsimUnpacking(b,a.xBit);
    doParsimUnpacking(b,a.eBit);
    doParsimUnpacking(b,a.v6Bit);
}

class OSPFv3OptionsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3OptionsDescriptor();
    virtual ~OSPFv3OptionsDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3OptionsDescriptor);

OSPFv3OptionsDescriptor::OSPFv3OptionsDescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3Options", "")
{
    propertynames = nullptr;
}

OSPFv3OptionsDescriptor::~OSPFv3OptionsDescriptor()
{
    delete[] propertynames;
}

bool OSPFv3OptionsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3Options *>(obj)!=nullptr;
}

const char **OSPFv3OptionsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3OptionsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3OptionsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int OSPFv3OptionsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3OptionsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reservedOne",
        "reservedTwo",
        "dcBit",
        "rBit",
        "nBit",
        "xBit",
        "eBit",
        "v6Bit",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int OSPFv3OptionsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "reservedOne")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "reservedTwo")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "dcBit")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "rBit")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "nBit")==0) return base+4;
    if (fieldName[0]=='x' && strcmp(fieldName, "xBit")==0) return base+5;
    if (fieldName[0]=='e' && strcmp(fieldName, "eBit")==0) return base+6;
    if (fieldName[0]=='v' && strcmp(fieldName, "v6Bit")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3OptionsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3OptionsDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3OptionsDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3OptionsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3Options *pp = (OSPFv3Options *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OSPFv3OptionsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3Options *pp = (OSPFv3Options *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->reservedOne);
        case 1: return bool2string(pp->reservedTwo);
        case 2: return bool2string(pp->dcBit);
        case 3: return bool2string(pp->rBit);
        case 4: return bool2string(pp->nBit);
        case 5: return bool2string(pp->xBit);
        case 6: return bool2string(pp->eBit);
        case 7: return bool2string(pp->v6Bit);
        default: return "";
    }
}

bool OSPFv3OptionsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3Options *pp = (OSPFv3Options *)object; (void)pp;
    switch (field) {
        case 0: pp->reservedOne = string2bool(value); return true;
        case 1: pp->reservedTwo = string2bool(value); return true;
        case 2: pp->dcBit = string2bool(value); return true;
        case 3: pp->rBit = string2bool(value); return true;
        case 4: pp->nBit = string2bool(value); return true;
        case 5: pp->xBit = string2bool(value); return true;
        case 6: pp->eBit = string2bool(value); return true;
        case 7: pp->v6Bit = string2bool(value); return true;
        default: return false;
    }
}

const char *OSPFv3OptionsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *OSPFv3OptionsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3Options *pp = (OSPFv3Options *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(OSPFv3TestPacket);

OSPFv3TestPacket::OSPFv3TestPacket(const char *name, int kind) : ::inet::OSPFv3Packet(name,kind)
{
    text_arraysize = 0;
    this->text = 0;
}

OSPFv3TestPacket::OSPFv3TestPacket(const OSPFv3TestPacket& other) : ::inet::OSPFv3Packet(other)
{
    text_arraysize = 0;
    this->text = 0;
    copy(other);
}

OSPFv3TestPacket::~OSPFv3TestPacket()
{
    delete [] this->text;
}

OSPFv3TestPacket& OSPFv3TestPacket::operator=(const OSPFv3TestPacket& other)
{
    if (this==&other) return *this;
    ::inet::OSPFv3Packet::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3TestPacket::copy(const OSPFv3TestPacket& other)
{
    delete [] this->text;
    this->text = (other.text_arraysize==0) ? nullptr : new char[other.text_arraysize];
    text_arraysize = other.text_arraysize;
    for (unsigned int i=0; i<text_arraysize; i++)
        this->text[i] = other.text[i];
}

void OSPFv3TestPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::OSPFv3Packet::parsimPack(b);
    b->pack(text_arraysize);
    doParsimArrayPacking(b,this->text,text_arraysize);
}

void OSPFv3TestPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::OSPFv3Packet::parsimUnpack(b);
    delete [] this->text;
    b->unpack(text_arraysize);
    if (text_arraysize==0) {
        this->text = 0;
    } else {
        this->text = new char[text_arraysize];
        doParsimArrayUnpacking(b,this->text,text_arraysize);
    }
}

void OSPFv3TestPacket::setTextArraySize(unsigned int size)
{
    char *text2 = (size==0) ? nullptr : new char[size];
    unsigned int sz = text_arraysize < size ? text_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        text2[i] = this->text[i];
    for (unsigned int i=sz; i<size; i++)
        text2[i] = 0;
    text_arraysize = size;
    delete [] this->text;
    this->text = text2;
}

unsigned int OSPFv3TestPacket::getTextArraySize() const
{
    return text_arraysize;
}

char OSPFv3TestPacket::getText(unsigned int k) const
{
    if (k>=text_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", text_arraysize, k);
    return this->text[k];
}

void OSPFv3TestPacket::setText(unsigned int k, char text)
{
    if (k>=text_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", text_arraysize, k);
    this->text[k] = text;
}

class OSPFv3TestPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3TestPacketDescriptor();
    virtual ~OSPFv3TestPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3TestPacketDescriptor);

OSPFv3TestPacketDescriptor::OSPFv3TestPacketDescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3TestPacket", "inet::OSPFv3Packet")
{
    propertynames = nullptr;
}

OSPFv3TestPacketDescriptor::~OSPFv3TestPacketDescriptor()
{
    delete[] propertynames;
}

bool OSPFv3TestPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3TestPacket *>(obj)!=nullptr;
}

const char **OSPFv3TestPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3TestPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3TestPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int OSPFv3TestPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3TestPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "text",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int OSPFv3TestPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "text")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3TestPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3TestPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3TestPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3TestPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3TestPacket *pp = (OSPFv3TestPacket *)object; (void)pp;
    switch (field) {
        case 0: return pp->getTextArraySize();
        default: return 0;
    }
}

std::string OSPFv3TestPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3TestPacket *pp = (OSPFv3TestPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getText(i));
        default: return "";
    }
}

bool OSPFv3TestPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3TestPacket *pp = (OSPFv3TestPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setText(i,string2long(value)); return true;
        default: return false;
    }
}

const char *OSPFv3TestPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *OSPFv3TestPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3TestPacket *pp = (OSPFv3TestPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(OSPFv3TestPacket6);

OSPFv3TestPacket6::OSPFv3TestPacket6(const char *name, int kind) : ::inet::OSPFv3Packet(name,kind)
{
    text_arraysize = 0;
    this->text = 0;
}

OSPFv3TestPacket6::OSPFv3TestPacket6(const OSPFv3TestPacket6& other) : ::inet::OSPFv3Packet(other)
{
    text_arraysize = 0;
    this->text = 0;
    copy(other);
}

OSPFv3TestPacket6::~OSPFv3TestPacket6()
{
    delete [] this->text;
}

OSPFv3TestPacket6& OSPFv3TestPacket6::operator=(const OSPFv3TestPacket6& other)
{
    if (this==&other) return *this;
    ::inet::OSPFv3Packet::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3TestPacket6::copy(const OSPFv3TestPacket6& other)
{
    delete [] this->text;
    this->text = (other.text_arraysize==0) ? nullptr : new char[other.text_arraysize];
    text_arraysize = other.text_arraysize;
    for (unsigned int i=0; i<text_arraysize; i++)
        this->text[i] = other.text[i];
}

void OSPFv3TestPacket6::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::OSPFv3Packet::parsimPack(b);
    b->pack(text_arraysize);
    doParsimArrayPacking(b,this->text,text_arraysize);
}

void OSPFv3TestPacket6::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::OSPFv3Packet::parsimUnpack(b);
    delete [] this->text;
    b->unpack(text_arraysize);
    if (text_arraysize==0) {
        this->text = 0;
    } else {
        this->text = new char[text_arraysize];
        doParsimArrayUnpacking(b,this->text,text_arraysize);
    }
}

void OSPFv3TestPacket6::setTextArraySize(unsigned int size)
{
    char *text2 = (size==0) ? nullptr : new char[size];
    unsigned int sz = text_arraysize < size ? text_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        text2[i] = this->text[i];
    for (unsigned int i=sz; i<size; i++)
        text2[i] = 0;
    text_arraysize = size;
    delete [] this->text;
    this->text = text2;
}

unsigned int OSPFv3TestPacket6::getTextArraySize() const
{
    return text_arraysize;
}

char OSPFv3TestPacket6::getText(unsigned int k) const
{
    if (k>=text_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", text_arraysize, k);
    return this->text[k];
}

void OSPFv3TestPacket6::setText(unsigned int k, char text)
{
    if (k>=text_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", text_arraysize, k);
    this->text[k] = text;
}

class OSPFv3TestPacket6Descriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3TestPacket6Descriptor();
    virtual ~OSPFv3TestPacket6Descriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3TestPacket6Descriptor);

OSPFv3TestPacket6Descriptor::OSPFv3TestPacket6Descriptor() : omnetpp::cClassDescriptor("inet::OSPFv3TestPacket6", "inet::OSPFv3Packet")
{
    propertynames = nullptr;
}

OSPFv3TestPacket6Descriptor::~OSPFv3TestPacket6Descriptor()
{
    delete[] propertynames;
}

bool OSPFv3TestPacket6Descriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3TestPacket6 *>(obj)!=nullptr;
}

const char **OSPFv3TestPacket6Descriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3TestPacket6Descriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3TestPacket6Descriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int OSPFv3TestPacket6Descriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3TestPacket6Descriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "text",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int OSPFv3TestPacket6Descriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "text")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3TestPacket6Descriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3TestPacket6Descriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3TestPacket6Descriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3TestPacket6Descriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3TestPacket6 *pp = (OSPFv3TestPacket6 *)object; (void)pp;
    switch (field) {
        case 0: return pp->getTextArraySize();
        default: return 0;
    }
}

std::string OSPFv3TestPacket6Descriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3TestPacket6 *pp = (OSPFv3TestPacket6 *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getText(i));
        default: return "";
    }
}

bool OSPFv3TestPacket6Descriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3TestPacket6 *pp = (OSPFv3TestPacket6 *)object; (void)pp;
    switch (field) {
        case 0: pp->setText(i,string2long(value)); return true;
        default: return false;
    }
}

const char *OSPFv3TestPacket6Descriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *OSPFv3TestPacket6Descriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3TestPacket6 *pp = (OSPFv3TestPacket6 *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(OSPFv3HelloPacket);

OSPFv3HelloPacket::OSPFv3HelloPacket(const char *name, int kind) : ::inet::OSPFv3Packet(name,kind)
{
    this->interfaceID = 0;
    this->routerPriority = 0;
    this->helloInterval = 0;
    this->deadInterval = 0;
    neighborID_arraysize = 0;
    this->neighborID = 0;
}

OSPFv3HelloPacket::OSPFv3HelloPacket(const OSPFv3HelloPacket& other) : ::inet::OSPFv3Packet(other)
{
    neighborID_arraysize = 0;
    this->neighborID = 0;
    copy(other);
}

OSPFv3HelloPacket::~OSPFv3HelloPacket()
{
    delete [] this->neighborID;
}

OSPFv3HelloPacket& OSPFv3HelloPacket::operator=(const OSPFv3HelloPacket& other)
{
    if (this==&other) return *this;
    ::inet::OSPFv3Packet::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3HelloPacket::copy(const OSPFv3HelloPacket& other)
{
    this->interfaceID = other.interfaceID;
    this->routerPriority = other.routerPriority;
    this->options = other.options;
    this->helloInterval = other.helloInterval;
    this->deadInterval = other.deadInterval;
    this->designatedRouterID = other.designatedRouterID;
    this->backupDesignatedRouterID = other.backupDesignatedRouterID;
    delete [] this->neighborID;
    this->neighborID = (other.neighborID_arraysize==0) ? nullptr : new IPv4Address[other.neighborID_arraysize];
    neighborID_arraysize = other.neighborID_arraysize;
    for (unsigned int i=0; i<neighborID_arraysize; i++)
        this->neighborID[i] = other.neighborID[i];
}

void OSPFv3HelloPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::OSPFv3Packet::parsimPack(b);
    doParsimPacking(b,this->interfaceID);
    doParsimPacking(b,this->routerPriority);
    doParsimPacking(b,this->options);
    doParsimPacking(b,this->helloInterval);
    doParsimPacking(b,this->deadInterval);
    doParsimPacking(b,this->designatedRouterID);
    doParsimPacking(b,this->backupDesignatedRouterID);
    b->pack(neighborID_arraysize);
    doParsimArrayPacking(b,this->neighborID,neighborID_arraysize);
}

void OSPFv3HelloPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::OSPFv3Packet::parsimUnpack(b);
    doParsimUnpacking(b,this->interfaceID);
    doParsimUnpacking(b,this->routerPriority);
    doParsimUnpacking(b,this->options);
    doParsimUnpacking(b,this->helloInterval);
    doParsimUnpacking(b,this->deadInterval);
    doParsimUnpacking(b,this->designatedRouterID);
    doParsimUnpacking(b,this->backupDesignatedRouterID);
    delete [] this->neighborID;
    b->unpack(neighborID_arraysize);
    if (neighborID_arraysize==0) {
        this->neighborID = 0;
    } else {
        this->neighborID = new IPv4Address[neighborID_arraysize];
        doParsimArrayUnpacking(b,this->neighborID,neighborID_arraysize);
    }
}

uint32_t OSPFv3HelloPacket::getInterfaceID() const
{
    return this->interfaceID;
}

void OSPFv3HelloPacket::setInterfaceID(uint32_t interfaceID)
{
    this->interfaceID = interfaceID;
}

uint8_t OSPFv3HelloPacket::getRouterPriority() const
{
    return this->routerPriority;
}

void OSPFv3HelloPacket::setRouterPriority(uint8_t routerPriority)
{
    this->routerPriority = routerPriority;
}

OSPFv3Options& OSPFv3HelloPacket::getOptions()
{
    return this->options;
}

void OSPFv3HelloPacket::setOptions(const OSPFv3Options& options)
{
    this->options = options;
}

uint16_t OSPFv3HelloPacket::getHelloInterval() const
{
    return this->helloInterval;
}

void OSPFv3HelloPacket::setHelloInterval(uint16_t helloInterval)
{
    this->helloInterval = helloInterval;
}

uint16_t OSPFv3HelloPacket::getDeadInterval() const
{
    return this->deadInterval;
}

void OSPFv3HelloPacket::setDeadInterval(uint16_t deadInterval)
{
    this->deadInterval = deadInterval;
}

IPv4Address& OSPFv3HelloPacket::getDesignatedRouterID()
{
    return this->designatedRouterID;
}

void OSPFv3HelloPacket::setDesignatedRouterID(const IPv4Address& designatedRouterID)
{
    this->designatedRouterID = designatedRouterID;
}

IPv4Address& OSPFv3HelloPacket::getBackupDesignatedRouterID()
{
    return this->backupDesignatedRouterID;
}

void OSPFv3HelloPacket::setBackupDesignatedRouterID(const IPv4Address& backupDesignatedRouterID)
{
    this->backupDesignatedRouterID = backupDesignatedRouterID;
}

void OSPFv3HelloPacket::setNeighborIDArraySize(unsigned int size)
{
    IPv4Address *neighborID2 = (size==0) ? nullptr : new IPv4Address[size];
    unsigned int sz = neighborID_arraysize < size ? neighborID_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        neighborID2[i] = this->neighborID[i];
    neighborID_arraysize = size;
    delete [] this->neighborID;
    this->neighborID = neighborID2;
}

unsigned int OSPFv3HelloPacket::getNeighborIDArraySize() const
{
    return neighborID_arraysize;
}

IPv4Address& OSPFv3HelloPacket::getNeighborID(unsigned int k)
{
    if (k>=neighborID_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", neighborID_arraysize, k);
    return this->neighborID[k];
}

void OSPFv3HelloPacket::setNeighborID(unsigned int k, const IPv4Address& neighborID)
{
    if (k>=neighborID_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", neighborID_arraysize, k);
    this->neighborID[k] = neighborID;
}

class OSPFv3HelloPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3HelloPacketDescriptor();
    virtual ~OSPFv3HelloPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3HelloPacketDescriptor);

OSPFv3HelloPacketDescriptor::OSPFv3HelloPacketDescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3HelloPacket", "inet::OSPFv3Packet")
{
    propertynames = nullptr;
}

OSPFv3HelloPacketDescriptor::~OSPFv3HelloPacketDescriptor()
{
    delete[] propertynames;
}

bool OSPFv3HelloPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3HelloPacket *>(obj)!=nullptr;
}

const char **OSPFv3HelloPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3HelloPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3HelloPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int OSPFv3HelloPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3HelloPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceID",
        "routerPriority",
        "options",
        "helloInterval",
        "deadInterval",
        "designatedRouterID",
        "backupDesignatedRouterID",
        "neighborID",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int OSPFv3HelloPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceID")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "routerPriority")==0) return base+1;
    if (fieldName[0]=='o' && strcmp(fieldName, "options")==0) return base+2;
    if (fieldName[0]=='h' && strcmp(fieldName, "helloInterval")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "deadInterval")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "designatedRouterID")==0) return base+5;
    if (fieldName[0]=='b' && strcmp(fieldName, "backupDesignatedRouterID")==0) return base+6;
    if (fieldName[0]=='n' && strcmp(fieldName, "neighborID")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3HelloPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",
        "uint8_t",
        "OSPFv3Options",
        "uint16_t",
        "uint16_t",
        "IPv4Address",
        "IPv4Address",
        "IPv4Address",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3HelloPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3HelloPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3HelloPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3HelloPacket *pp = (OSPFv3HelloPacket *)object; (void)pp;
    switch (field) {
        case 7: return pp->getNeighborIDArraySize();
        default: return 0;
    }
}

std::string OSPFv3HelloPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3HelloPacket *pp = (OSPFv3HelloPacket *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getInterfaceID());
        case 1: return ulong2string(pp->getRouterPriority());
        case 2: {std::stringstream out; out << pp->getOptions(); return out.str();}
        case 3: return ulong2string(pp->getHelloInterval());
        case 4: return ulong2string(pp->getDeadInterval());
        case 5: {std::stringstream out; out << pp->getDesignatedRouterID(); return out.str();}
        case 6: {std::stringstream out; out << pp->getBackupDesignatedRouterID(); return out.str();}
        case 7: {std::stringstream out; out << pp->getNeighborID(i); return out.str();}
        default: return "";
    }
}

bool OSPFv3HelloPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3HelloPacket *pp = (OSPFv3HelloPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setInterfaceID(string2ulong(value)); return true;
        case 1: pp->setRouterPriority(string2ulong(value)); return true;
        case 3: pp->setHelloInterval(string2ulong(value)); return true;
        case 4: pp->setDeadInterval(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFv3HelloPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(OSPFv3Options));
        case 5: return omnetpp::opp_typename(typeid(IPv4Address));
        case 6: return omnetpp::opp_typename(typeid(IPv4Address));
        case 7: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *OSPFv3HelloPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3HelloPacket *pp = (OSPFv3HelloPacket *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getOptions()); break;
        case 5: return (void *)(&pp->getDesignatedRouterID()); break;
        case 6: return (void *)(&pp->getBackupDesignatedRouterID()); break;
        case 7: return (void *)(&pp->getNeighborID(i)); break;
        default: return nullptr;
    }
}

Register_Class(OSPFv3LSAHeader);

OSPFv3LSAHeader::OSPFv3LSAHeader() : ::omnetpp::cObject()
{
    this->lsaAge = 0;
    this->lsaType = 0;
    this->lsaSequenceNumber = 0;
    this->lsaChecksum = 0;
    this->lsaLength = 0;
}

OSPFv3LSAHeader::OSPFv3LSAHeader(const OSPFv3LSAHeader& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

OSPFv3LSAHeader::~OSPFv3LSAHeader()
{
}

OSPFv3LSAHeader& OSPFv3LSAHeader::operator=(const OSPFv3LSAHeader& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3LSAHeader::copy(const OSPFv3LSAHeader& other)
{
    this->lsaAge = other.lsaAge;
    this->lsaType = other.lsaType;
    this->linkStateID = other.linkStateID;
    this->advertisingRouter = other.advertisingRouter;
    this->lsaSequenceNumber = other.lsaSequenceNumber;
    this->lsaChecksum = other.lsaChecksum;
    this->lsaLength = other.lsaLength;
}

void OSPFv3LSAHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->lsaAge);
    doParsimPacking(b,this->lsaType);
    doParsimPacking(b,this->linkStateID);
    doParsimPacking(b,this->advertisingRouter);
    doParsimPacking(b,this->lsaSequenceNumber);
    doParsimPacking(b,this->lsaChecksum);
    doParsimPacking(b,this->lsaLength);
}

void OSPFv3LSAHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->lsaAge);
    doParsimUnpacking(b,this->lsaType);
    doParsimUnpacking(b,this->linkStateID);
    doParsimUnpacking(b,this->advertisingRouter);
    doParsimUnpacking(b,this->lsaSequenceNumber);
    doParsimUnpacking(b,this->lsaChecksum);
    doParsimUnpacking(b,this->lsaLength);
}

uint16_t OSPFv3LSAHeader::getLsaAge() const
{
    return this->lsaAge;
}

void OSPFv3LSAHeader::setLsaAge(uint16_t lsaAge)
{
    this->lsaAge = lsaAge;
}

uint16_t OSPFv3LSAHeader::getLsaType() const
{
    return this->lsaType;
}

void OSPFv3LSAHeader::setLsaType(uint16_t lsaType)
{
    this->lsaType = lsaType;
}

IPv4Address& OSPFv3LSAHeader::getLinkStateID()
{
    return this->linkStateID;
}

void OSPFv3LSAHeader::setLinkStateID(const IPv4Address& linkStateID)
{
    this->linkStateID = linkStateID;
}

IPv4Address& OSPFv3LSAHeader::getAdvertisingRouter()
{
    return this->advertisingRouter;
}

void OSPFv3LSAHeader::setAdvertisingRouter(const IPv4Address& advertisingRouter)
{
    this->advertisingRouter = advertisingRouter;
}

uint32_t OSPFv3LSAHeader::getLsaSequenceNumber() const
{
    return this->lsaSequenceNumber;
}

void OSPFv3LSAHeader::setLsaSequenceNumber(uint32_t lsaSequenceNumber)
{
    this->lsaSequenceNumber = lsaSequenceNumber;
}

uint16_t OSPFv3LSAHeader::getLsaChecksum() const
{
    return this->lsaChecksum;
}

void OSPFv3LSAHeader::setLsaChecksum(uint16_t lsaChecksum)
{
    this->lsaChecksum = lsaChecksum;
}

uint16_t OSPFv3LSAHeader::getLsaLength() const
{
    return this->lsaLength;
}

void OSPFv3LSAHeader::setLsaLength(uint16_t lsaLength)
{
    this->lsaLength = lsaLength;
}

class OSPFv3LSAHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3LSAHeaderDescriptor();
    virtual ~OSPFv3LSAHeaderDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3LSAHeaderDescriptor);

OSPFv3LSAHeaderDescriptor::OSPFv3LSAHeaderDescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3LSAHeader", "omnetpp::cObject")
{
    propertynames = nullptr;
}

OSPFv3LSAHeaderDescriptor::~OSPFv3LSAHeaderDescriptor()
{
    delete[] propertynames;
}

bool OSPFv3LSAHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3LSAHeader *>(obj)!=nullptr;
}

const char **OSPFv3LSAHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3LSAHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3LSAHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int OSPFv3LSAHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3LSAHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lsaAge",
        "lsaType",
        "linkStateID",
        "advertisingRouter",
        "lsaSequenceNumber",
        "lsaChecksum",
        "lsaLength",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int OSPFv3LSAHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsaAge")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsaType")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "linkStateID")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "advertisingRouter")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsaSequenceNumber")==0) return base+4;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsaChecksum")==0) return base+5;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsaLength")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3LSAHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",
        "uint16_t",
        "IPv4Address",
        "IPv4Address",
        "uint32_t",
        "uint16_t",
        "uint16_t",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3LSAHeaderDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3LSAHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3LSAHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSAHeader *pp = (OSPFv3LSAHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OSPFv3LSAHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSAHeader *pp = (OSPFv3LSAHeader *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getLsaAge());
        case 1: return ulong2string(pp->getLsaType());
        case 2: {std::stringstream out; out << pp->getLinkStateID(); return out.str();}
        case 3: {std::stringstream out; out << pp->getAdvertisingRouter(); return out.str();}
        case 4: return ulong2string(pp->getLsaSequenceNumber());
        case 5: return ulong2string(pp->getLsaChecksum());
        case 6: return ulong2string(pp->getLsaLength());
        default: return "";
    }
}

bool OSPFv3LSAHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSAHeader *pp = (OSPFv3LSAHeader *)object; (void)pp;
    switch (field) {
        case 0: pp->setLsaAge(string2ulong(value)); return true;
        case 1: pp->setLsaType(string2ulong(value)); return true;
        case 4: pp->setLsaSequenceNumber(string2ulong(value)); return true;
        case 5: pp->setLsaChecksum(string2ulong(value)); return true;
        case 6: pp->setLsaLength(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFv3LSAHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(IPv4Address));
        case 3: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *OSPFv3LSAHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSAHeader *pp = (OSPFv3LSAHeader *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getLinkStateID()); break;
        case 3: return (void *)(&pp->getAdvertisingRouter()); break;
        default: return nullptr;
    }
}

Register_Class(OSPFv3LSA);

OSPFv3LSA::OSPFv3LSA() : ::omnetpp::cObject()
{
}

OSPFv3LSA::OSPFv3LSA(const OSPFv3LSA& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

OSPFv3LSA::~OSPFv3LSA()
{
}

OSPFv3LSA& OSPFv3LSA::operator=(const OSPFv3LSA& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3LSA::copy(const OSPFv3LSA& other)
{
    this->header = other.header;
}

void OSPFv3LSA::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->header);
}

void OSPFv3LSA::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->header);
}

OSPFv3LSAHeader& OSPFv3LSA::getHeader()
{
    return this->header;
}

void OSPFv3LSA::setHeader(const OSPFv3LSAHeader& header)
{
    this->header = header;
}

class OSPFv3LSADescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3LSADescriptor();
    virtual ~OSPFv3LSADescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3LSADescriptor);

OSPFv3LSADescriptor::OSPFv3LSADescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3LSA", "omnetpp::cObject")
{
    propertynames = nullptr;
}

OSPFv3LSADescriptor::~OSPFv3LSADescriptor()
{
    delete[] propertynames;
}

bool OSPFv3LSADescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3LSA *>(obj)!=nullptr;
}

const char **OSPFv3LSADescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3LSADescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3LSADescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int OSPFv3LSADescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3LSADescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "header",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int OSPFv3LSADescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "header")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3LSADescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "OSPFv3LSAHeader",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3LSADescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3LSADescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3LSADescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSA *pp = (OSPFv3LSA *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OSPFv3LSADescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSA *pp = (OSPFv3LSA *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getHeader(); return out.str();}
        default: return "";
    }
}

bool OSPFv3LSADescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSA *pp = (OSPFv3LSA *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OSPFv3LSADescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(OSPFv3LSAHeader));
        default: return nullptr;
    };
}

void *OSPFv3LSADescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSA *pp = (OSPFv3LSA *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getHeader()); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::OSPFv3LSAFunctionCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::OSPFv3LSAFunctionCode"));
    e->insert(ROUTER_LSA, "ROUTER_LSA");
    e->insert(NETWORK_LSA, "NETWORK_LSA");
    e->insert(INTER_AREA_PREFIX_LSA, "INTER_AREA_PREFIX_LSA");
    e->insert(INTER_AREA_ROUTER_LSA, "INTER_AREA_ROUTER_LSA");
    e->insert(AS_EXTERNAL_LSA, "AS_EXTERNAL_LSA");
    e->insert(DEPRECATED, "DEPRECATED");
    e->insert(NSSA_LSA, "NSSA_LSA");
    e->insert(LINK_LSA, "LINK_LSA");
    e->insert(INTRA_AREA_PREFIX_LSA, "INTRA_AREA_PREFIX_LSA");
);

OSPFv3LSAPrefix::OSPFv3LSAPrefix()
{
    this->dnBit = 0;
    this->pBit = 0;
    this->xBit = 0;
    this->laBit = 0;
    this->nuBit = 0;
    this->prefixLen = 0;
    this->metric = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const OSPFv3LSAPrefix& a)
{
    doParsimPacking(b,a.dnBit);
    doParsimPacking(b,a.pBit);
    doParsimPacking(b,a.xBit);
    doParsimPacking(b,a.laBit);
    doParsimPacking(b,a.nuBit);
    doParsimPacking(b,a.prefixLen);
    doParsimPacking(b,a.addressPrefix);
    doParsimPacking(b,a.metric);
}

void __doUnpacking(omnetpp::cCommBuffer *b, OSPFv3LSAPrefix& a)
{
    doParsimUnpacking(b,a.dnBit);
    doParsimUnpacking(b,a.pBit);
    doParsimUnpacking(b,a.xBit);
    doParsimUnpacking(b,a.laBit);
    doParsimUnpacking(b,a.nuBit);
    doParsimUnpacking(b,a.prefixLen);
    doParsimUnpacking(b,a.addressPrefix);
    doParsimUnpacking(b,a.metric);
}

class OSPFv3LSAPrefixDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3LSAPrefixDescriptor();
    virtual ~OSPFv3LSAPrefixDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3LSAPrefixDescriptor);

OSPFv3LSAPrefixDescriptor::OSPFv3LSAPrefixDescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3LSAPrefix", "")
{
    propertynames = nullptr;
}

OSPFv3LSAPrefixDescriptor::~OSPFv3LSAPrefixDescriptor()
{
    delete[] propertynames;
}

bool OSPFv3LSAPrefixDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3LSAPrefix *>(obj)!=nullptr;
}

const char **OSPFv3LSAPrefixDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3LSAPrefixDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3LSAPrefixDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int OSPFv3LSAPrefixDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3LSAPrefixDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "dnBit",
        "pBit",
        "xBit",
        "laBit",
        "nuBit",
        "prefixLen",
        "addressPrefix",
        "metric",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int OSPFv3LSAPrefixDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dnBit")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pBit")==0) return base+1;
    if (fieldName[0]=='x' && strcmp(fieldName, "xBit")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "laBit")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "nuBit")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixLen")==0) return base+5;
    if (fieldName[0]=='a' && strcmp(fieldName, "addressPrefix")==0) return base+6;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3LSAPrefixDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "uint8_t",
        "L3Address",
        "uint16_t",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3LSAPrefixDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3LSAPrefixDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3LSAPrefixDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSAPrefix *pp = (OSPFv3LSAPrefix *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OSPFv3LSAPrefixDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSAPrefix *pp = (OSPFv3LSAPrefix *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->dnBit);
        case 1: return bool2string(pp->pBit);
        case 2: return bool2string(pp->xBit);
        case 3: return bool2string(pp->laBit);
        case 4: return bool2string(pp->nuBit);
        case 5: return ulong2string(pp->prefixLen);
        case 6: {std::stringstream out; out << pp->addressPrefix; return out.str();}
        case 7: return ulong2string(pp->metric);
        default: return "";
    }
}

bool OSPFv3LSAPrefixDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSAPrefix *pp = (OSPFv3LSAPrefix *)object; (void)pp;
    switch (field) {
        case 0: pp->dnBit = string2bool(value); return true;
        case 1: pp->pBit = string2bool(value); return true;
        case 2: pp->xBit = string2bool(value); return true;
        case 3: pp->laBit = string2bool(value); return true;
        case 4: pp->nuBit = string2bool(value); return true;
        case 5: pp->prefixLen = string2ulong(value); return true;
        case 7: pp->metric = string2ulong(value); return true;
        default: return false;
    }
}

const char *OSPFv3LSAPrefixDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 6: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *OSPFv3LSAPrefixDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSAPrefix *pp = (OSPFv3LSAPrefix *)object; (void)pp;
    switch (field) {
        case 6: return (void *)(&pp->addressPrefix); break;
        default: return nullptr;
    }
}

OSPFv3LinkLSAPrefix::OSPFv3LinkLSAPrefix()
{
    this->dnBit = false;
    this->pBit = false;
    this->xBit = false;
    this->laBit = false;
    this->nuBit = false;
    this->prefixLen = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const OSPFv3LinkLSAPrefix& a)
{
    doParsimPacking(b,a.dnBit);
    doParsimPacking(b,a.pBit);
    doParsimPacking(b,a.xBit);
    doParsimPacking(b,a.laBit);
    doParsimPacking(b,a.nuBit);
    doParsimPacking(b,a.prefixLen);
    doParsimPacking(b,a.addressPrefix);
}

void __doUnpacking(omnetpp::cCommBuffer *b, OSPFv3LinkLSAPrefix& a)
{
    doParsimUnpacking(b,a.dnBit);
    doParsimUnpacking(b,a.pBit);
    doParsimUnpacking(b,a.xBit);
    doParsimUnpacking(b,a.laBit);
    doParsimUnpacking(b,a.nuBit);
    doParsimUnpacking(b,a.prefixLen);
    doParsimUnpacking(b,a.addressPrefix);
}

class OSPFv3LinkLSAPrefixDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3LinkLSAPrefixDescriptor();
    virtual ~OSPFv3LinkLSAPrefixDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3LinkLSAPrefixDescriptor);

OSPFv3LinkLSAPrefixDescriptor::OSPFv3LinkLSAPrefixDescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3LinkLSAPrefix", "")
{
    propertynames = nullptr;
}

OSPFv3LinkLSAPrefixDescriptor::~OSPFv3LinkLSAPrefixDescriptor()
{
    delete[] propertynames;
}

bool OSPFv3LinkLSAPrefixDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3LinkLSAPrefix *>(obj)!=nullptr;
}

const char **OSPFv3LinkLSAPrefixDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3LinkLSAPrefixDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3LinkLSAPrefixDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int OSPFv3LinkLSAPrefixDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3LinkLSAPrefixDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "dnBit",
        "pBit",
        "xBit",
        "laBit",
        "nuBit",
        "prefixLen",
        "addressPrefix",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int OSPFv3LinkLSAPrefixDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dnBit")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pBit")==0) return base+1;
    if (fieldName[0]=='x' && strcmp(fieldName, "xBit")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "laBit")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "nuBit")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixLen")==0) return base+5;
    if (fieldName[0]=='a' && strcmp(fieldName, "addressPrefix")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3LinkLSAPrefixDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "uint8_t",
        "L3Address",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3LinkLSAPrefixDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3LinkLSAPrefixDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3LinkLSAPrefixDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LinkLSAPrefix *pp = (OSPFv3LinkLSAPrefix *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OSPFv3LinkLSAPrefixDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LinkLSAPrefix *pp = (OSPFv3LinkLSAPrefix *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->dnBit);
        case 1: return bool2string(pp->pBit);
        case 2: return bool2string(pp->xBit);
        case 3: return bool2string(pp->laBit);
        case 4: return bool2string(pp->nuBit);
        case 5: return ulong2string(pp->prefixLen);
        case 6: {std::stringstream out; out << pp->addressPrefix; return out.str();}
        default: return "";
    }
}

bool OSPFv3LinkLSAPrefixDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LinkLSAPrefix *pp = (OSPFv3LinkLSAPrefix *)object; (void)pp;
    switch (field) {
        case 0: pp->dnBit = string2bool(value); return true;
        case 1: pp->pBit = string2bool(value); return true;
        case 2: pp->xBit = string2bool(value); return true;
        case 3: pp->laBit = string2bool(value); return true;
        case 4: pp->nuBit = string2bool(value); return true;
        case 5: pp->prefixLen = string2ulong(value); return true;
        default: return false;
    }
}

const char *OSPFv3LinkLSAPrefixDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 6: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *OSPFv3LinkLSAPrefixDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LinkLSAPrefix *pp = (OSPFv3LinkLSAPrefix *)object; (void)pp;
    switch (field) {
        case 6: return (void *)(&pp->addressPrefix); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::OSPFv3RouterLSAType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::OSPFv3RouterLSAType"));
    e->insert(POINT_TO_POINT, "POINT_TO_POINT");
    e->insert(TRANSIT_NETWORK, "TRANSIT_NETWORK");
    e->insert(RESERVED, "RESERVED");
    e->insert(VIRTUAL_LINK, "VIRTUAL_LINK");
);

OSPFv3RouterLSABody::OSPFv3RouterLSABody()
{
    this->type = 0;
    this->metric = 0;
    this->interfaceID = 0;
    this->neighborInterfaceID = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const OSPFv3RouterLSABody& a)
{
    doParsimPacking(b,a.type);
    doParsimPacking(b,a.metric);
    doParsimPacking(b,a.interfaceID);
    doParsimPacking(b,a.neighborInterfaceID);
    doParsimPacking(b,a.neighborRouterID);
}

void __doUnpacking(omnetpp::cCommBuffer *b, OSPFv3RouterLSABody& a)
{
    doParsimUnpacking(b,a.type);
    doParsimUnpacking(b,a.metric);
    doParsimUnpacking(b,a.interfaceID);
    doParsimUnpacking(b,a.neighborInterfaceID);
    doParsimUnpacking(b,a.neighborRouterID);
}

class OSPFv3RouterLSABodyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3RouterLSABodyDescriptor();
    virtual ~OSPFv3RouterLSABodyDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3RouterLSABodyDescriptor);

OSPFv3RouterLSABodyDescriptor::OSPFv3RouterLSABodyDescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3RouterLSABody", "")
{
    propertynames = nullptr;
}

OSPFv3RouterLSABodyDescriptor::~OSPFv3RouterLSABodyDescriptor()
{
    delete[] propertynames;
}

bool OSPFv3RouterLSABodyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3RouterLSABody *>(obj)!=nullptr;
}

const char **OSPFv3RouterLSABodyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3RouterLSABodyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3RouterLSABodyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int OSPFv3RouterLSABodyDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3RouterLSABodyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "metric",
        "interfaceID",
        "neighborInterfaceID",
        "neighborRouterID",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int OSPFv3RouterLSABodyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceID")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "neighborInterfaceID")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "neighborRouterID")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3RouterLSABodyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
        "uint16_t",
        "uint32_t",
        "uint32_t",
        "IPv4Address",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3RouterLSABodyDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3RouterLSABodyDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3RouterLSABodyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3RouterLSABody *pp = (OSPFv3RouterLSABody *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OSPFv3RouterLSABodyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3RouterLSABody *pp = (OSPFv3RouterLSABody *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->type);
        case 1: return ulong2string(pp->metric);
        case 2: return ulong2string(pp->interfaceID);
        case 3: return ulong2string(pp->neighborInterfaceID);
        case 4: {std::stringstream out; out << pp->neighborRouterID; return out.str();}
        default: return "";
    }
}

bool OSPFv3RouterLSABodyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3RouterLSABody *pp = (OSPFv3RouterLSABody *)object; (void)pp;
    switch (field) {
        case 0: pp->type = string2ulong(value); return true;
        case 1: pp->metric = string2ulong(value); return true;
        case 2: pp->interfaceID = string2ulong(value); return true;
        case 3: pp->neighborInterfaceID = string2ulong(value); return true;
        default: return false;
    }
}

const char *OSPFv3RouterLSABodyDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *OSPFv3RouterLSABodyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3RouterLSABody *pp = (OSPFv3RouterLSABody *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->neighborRouterID); break;
        default: return nullptr;
    }
}

Register_Class(OSPFv3RouterLSA);

OSPFv3RouterLSA::OSPFv3RouterLSA() : ::inet::OSPFv3LSA()
{
    this->ntBit = false;
    this->xBit = false;
    this->vBit = false;
    this->eBit = false;
    this->bBit = false;
    routers_arraysize = 0;
    this->routers = 0;
}

OSPFv3RouterLSA::OSPFv3RouterLSA(const OSPFv3RouterLSA& other) : ::inet::OSPFv3LSA(other)
{
    routers_arraysize = 0;
    this->routers = 0;
    copy(other);
}

OSPFv3RouterLSA::~OSPFv3RouterLSA()
{
    delete [] this->routers;
}

OSPFv3RouterLSA& OSPFv3RouterLSA::operator=(const OSPFv3RouterLSA& other)
{
    if (this==&other) return *this;
    ::inet::OSPFv3LSA::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3RouterLSA::copy(const OSPFv3RouterLSA& other)
{
    this->ntBit = other.ntBit;
    this->xBit = other.xBit;
    this->vBit = other.vBit;
    this->eBit = other.eBit;
    this->bBit = other.bBit;
    this->ospfOptions = other.ospfOptions;
    delete [] this->routers;
    this->routers = (other.routers_arraysize==0) ? nullptr : new OSPFv3RouterLSABody[other.routers_arraysize];
    routers_arraysize = other.routers_arraysize;
    for (unsigned int i=0; i<routers_arraysize; i++)
        this->routers[i] = other.routers[i];
}

void OSPFv3RouterLSA::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::OSPFv3LSA::parsimPack(b);
    doParsimPacking(b,this->ntBit);
    doParsimPacking(b,this->xBit);
    doParsimPacking(b,this->vBit);
    doParsimPacking(b,this->eBit);
    doParsimPacking(b,this->bBit);
    doParsimPacking(b,this->ospfOptions);
    b->pack(routers_arraysize);
    doParsimArrayPacking(b,this->routers,routers_arraysize);
}

void OSPFv3RouterLSA::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::OSPFv3LSA::parsimUnpack(b);
    doParsimUnpacking(b,this->ntBit);
    doParsimUnpacking(b,this->xBit);
    doParsimUnpacking(b,this->vBit);
    doParsimUnpacking(b,this->eBit);
    doParsimUnpacking(b,this->bBit);
    doParsimUnpacking(b,this->ospfOptions);
    delete [] this->routers;
    b->unpack(routers_arraysize);
    if (routers_arraysize==0) {
        this->routers = 0;
    } else {
        this->routers = new OSPFv3RouterLSABody[routers_arraysize];
        doParsimArrayUnpacking(b,this->routers,routers_arraysize);
    }
}

bool OSPFv3RouterLSA::getNtBit() const
{
    return this->ntBit;
}

void OSPFv3RouterLSA::setNtBit(bool ntBit)
{
    this->ntBit = ntBit;
}

bool OSPFv3RouterLSA::getXBit() const
{
    return this->xBit;
}

void OSPFv3RouterLSA::setXBit(bool xBit)
{
    this->xBit = xBit;
}

bool OSPFv3RouterLSA::getVBit() const
{
    return this->vBit;
}

void OSPFv3RouterLSA::setVBit(bool vBit)
{
    this->vBit = vBit;
}

bool OSPFv3RouterLSA::getEBit() const
{
    return this->eBit;
}

void OSPFv3RouterLSA::setEBit(bool eBit)
{
    this->eBit = eBit;
}

bool OSPFv3RouterLSA::getBBit() const
{
    return this->bBit;
}

void OSPFv3RouterLSA::setBBit(bool bBit)
{
    this->bBit = bBit;
}

OSPFv3Options& OSPFv3RouterLSA::getOspfOptions()
{
    return this->ospfOptions;
}

void OSPFv3RouterLSA::setOspfOptions(const OSPFv3Options& ospfOptions)
{
    this->ospfOptions = ospfOptions;
}

void OSPFv3RouterLSA::setRoutersArraySize(unsigned int size)
{
    OSPFv3RouterLSABody *routers2 = (size==0) ? nullptr : new OSPFv3RouterLSABody[size];
    unsigned int sz = routers_arraysize < size ? routers_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        routers2[i] = this->routers[i];
    routers_arraysize = size;
    delete [] this->routers;
    this->routers = routers2;
}

unsigned int OSPFv3RouterLSA::getRoutersArraySize() const
{
    return routers_arraysize;
}

OSPFv3RouterLSABody& OSPFv3RouterLSA::getRouters(unsigned int k)
{
    if (k>=routers_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", routers_arraysize, k);
    return this->routers[k];
}

void OSPFv3RouterLSA::setRouters(unsigned int k, const OSPFv3RouterLSABody& routers)
{
    if (k>=routers_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", routers_arraysize, k);
    this->routers[k] = routers;
}

class OSPFv3RouterLSADescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3RouterLSADescriptor();
    virtual ~OSPFv3RouterLSADescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3RouterLSADescriptor);

OSPFv3RouterLSADescriptor::OSPFv3RouterLSADescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3RouterLSA", "inet::OSPFv3LSA")
{
    propertynames = nullptr;
}

OSPFv3RouterLSADescriptor::~OSPFv3RouterLSADescriptor()
{
    delete[] propertynames;
}

bool OSPFv3RouterLSADescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3RouterLSA *>(obj)!=nullptr;
}

const char **OSPFv3RouterLSADescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3RouterLSADescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3RouterLSADescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int OSPFv3RouterLSADescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3RouterLSADescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ntBit",
        "xBit",
        "vBit",
        "eBit",
        "bBit",
        "ospfOptions",
        "routers",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int OSPFv3RouterLSADescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "ntBit")==0) return base+0;
    if (fieldName[0]=='x' && strcmp(fieldName, "xBit")==0) return base+1;
    if (fieldName[0]=='v' && strcmp(fieldName, "vBit")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "eBit")==0) return base+3;
    if (fieldName[0]=='b' && strcmp(fieldName, "bBit")==0) return base+4;
    if (fieldName[0]=='o' && strcmp(fieldName, "ospfOptions")==0) return base+5;
    if (fieldName[0]=='r' && strcmp(fieldName, "routers")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3RouterLSADescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "OSPFv3Options",
        "OSPFv3RouterLSABody",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3RouterLSADescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3RouterLSADescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3RouterLSADescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3RouterLSA *pp = (OSPFv3RouterLSA *)object; (void)pp;
    switch (field) {
        case 6: return pp->getRoutersArraySize();
        default: return 0;
    }
}

std::string OSPFv3RouterLSADescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3RouterLSA *pp = (OSPFv3RouterLSA *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getNtBit());
        case 1: return bool2string(pp->getXBit());
        case 2: return bool2string(pp->getVBit());
        case 3: return bool2string(pp->getEBit());
        case 4: return bool2string(pp->getBBit());
        case 5: {std::stringstream out; out << pp->getOspfOptions(); return out.str();}
        case 6: {std::stringstream out; out << pp->getRouters(i); return out.str();}
        default: return "";
    }
}

bool OSPFv3RouterLSADescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3RouterLSA *pp = (OSPFv3RouterLSA *)object; (void)pp;
    switch (field) {
        case 0: pp->setNtBit(string2bool(value)); return true;
        case 1: pp->setXBit(string2bool(value)); return true;
        case 2: pp->setVBit(string2bool(value)); return true;
        case 3: pp->setEBit(string2bool(value)); return true;
        case 4: pp->setBBit(string2bool(value)); return true;
        default: return false;
    }
}

const char *OSPFv3RouterLSADescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 5: return omnetpp::opp_typename(typeid(OSPFv3Options));
        case 6: return omnetpp::opp_typename(typeid(OSPFv3RouterLSABody));
        default: return nullptr;
    };
}

void *OSPFv3RouterLSADescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3RouterLSA *pp = (OSPFv3RouterLSA *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getOspfOptions()); break;
        case 6: return (void *)(&pp->getRouters(i)); break;
        default: return nullptr;
    }
}

Register_Class(OSPFv3NetworkLSA);

OSPFv3NetworkLSA::OSPFv3NetworkLSA() : ::inet::OSPFv3LSA()
{
    attachedRouter_arraysize = 0;
    this->attachedRouter = 0;
}

OSPFv3NetworkLSA::OSPFv3NetworkLSA(const OSPFv3NetworkLSA& other) : ::inet::OSPFv3LSA(other)
{
    attachedRouter_arraysize = 0;
    this->attachedRouter = 0;
    copy(other);
}

OSPFv3NetworkLSA::~OSPFv3NetworkLSA()
{
    delete [] this->attachedRouter;
}

OSPFv3NetworkLSA& OSPFv3NetworkLSA::operator=(const OSPFv3NetworkLSA& other)
{
    if (this==&other) return *this;
    ::inet::OSPFv3LSA::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3NetworkLSA::copy(const OSPFv3NetworkLSA& other)
{
    this->ospfOptions = other.ospfOptions;
    delete [] this->attachedRouter;
    this->attachedRouter = (other.attachedRouter_arraysize==0) ? nullptr : new IPv4Address[other.attachedRouter_arraysize];
    attachedRouter_arraysize = other.attachedRouter_arraysize;
    for (unsigned int i=0; i<attachedRouter_arraysize; i++)
        this->attachedRouter[i] = other.attachedRouter[i];
}

void OSPFv3NetworkLSA::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::OSPFv3LSA::parsimPack(b);
    doParsimPacking(b,this->ospfOptions);
    b->pack(attachedRouter_arraysize);
    doParsimArrayPacking(b,this->attachedRouter,attachedRouter_arraysize);
}

void OSPFv3NetworkLSA::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::OSPFv3LSA::parsimUnpack(b);
    doParsimUnpacking(b,this->ospfOptions);
    delete [] this->attachedRouter;
    b->unpack(attachedRouter_arraysize);
    if (attachedRouter_arraysize==0) {
        this->attachedRouter = 0;
    } else {
        this->attachedRouter = new IPv4Address[attachedRouter_arraysize];
        doParsimArrayUnpacking(b,this->attachedRouter,attachedRouter_arraysize);
    }
}

OSPFv3Options& OSPFv3NetworkLSA::getOspfOptions()
{
    return this->ospfOptions;
}

void OSPFv3NetworkLSA::setOspfOptions(const OSPFv3Options& ospfOptions)
{
    this->ospfOptions = ospfOptions;
}

void OSPFv3NetworkLSA::setAttachedRouterArraySize(unsigned int size)
{
    IPv4Address *attachedRouter2 = (size==0) ? nullptr : new IPv4Address[size];
    unsigned int sz = attachedRouter_arraysize < size ? attachedRouter_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        attachedRouter2[i] = this->attachedRouter[i];
    attachedRouter_arraysize = size;
    delete [] this->attachedRouter;
    this->attachedRouter = attachedRouter2;
}

unsigned int OSPFv3NetworkLSA::getAttachedRouterArraySize() const
{
    return attachedRouter_arraysize;
}

IPv4Address& OSPFv3NetworkLSA::getAttachedRouter(unsigned int k)
{
    if (k>=attachedRouter_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", attachedRouter_arraysize, k);
    return this->attachedRouter[k];
}

void OSPFv3NetworkLSA::setAttachedRouter(unsigned int k, const IPv4Address& attachedRouter)
{
    if (k>=attachedRouter_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", attachedRouter_arraysize, k);
    this->attachedRouter[k] = attachedRouter;
}

class OSPFv3NetworkLSADescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3NetworkLSADescriptor();
    virtual ~OSPFv3NetworkLSADescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3NetworkLSADescriptor);

OSPFv3NetworkLSADescriptor::OSPFv3NetworkLSADescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3NetworkLSA", "inet::OSPFv3LSA")
{
    propertynames = nullptr;
}

OSPFv3NetworkLSADescriptor::~OSPFv3NetworkLSADescriptor()
{
    delete[] propertynames;
}

bool OSPFv3NetworkLSADescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3NetworkLSA *>(obj)!=nullptr;
}

const char **OSPFv3NetworkLSADescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3NetworkLSADescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3NetworkLSADescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int OSPFv3NetworkLSADescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3NetworkLSADescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ospfOptions",
        "attachedRouter",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int OSPFv3NetworkLSADescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "ospfOptions")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "attachedRouter")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3NetworkLSADescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "OSPFv3Options",
        "IPv4Address",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3NetworkLSADescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3NetworkLSADescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3NetworkLSADescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3NetworkLSA *pp = (OSPFv3NetworkLSA *)object; (void)pp;
    switch (field) {
        case 1: return pp->getAttachedRouterArraySize();
        default: return 0;
    }
}

std::string OSPFv3NetworkLSADescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3NetworkLSA *pp = (OSPFv3NetworkLSA *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getOspfOptions(); return out.str();}
        case 1: {std::stringstream out; out << pp->getAttachedRouter(i); return out.str();}
        default: return "";
    }
}

bool OSPFv3NetworkLSADescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3NetworkLSA *pp = (OSPFv3NetworkLSA *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OSPFv3NetworkLSADescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(OSPFv3Options));
        case 1: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *OSPFv3NetworkLSADescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3NetworkLSA *pp = (OSPFv3NetworkLSA *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getOspfOptions()); break;
        case 1: return (void *)(&pp->getAttachedRouter(i)); break;
        default: return nullptr;
    }
}

Register_Class(OSPFv3InterAreaPrefixLSA);

OSPFv3InterAreaPrefixLSA::OSPFv3InterAreaPrefixLSA() : ::inet::OSPFv3LSA()
{
    this->dnBit = false;
    this->pBit = false;
    this->xBit = false;
    this->laBit = false;
    this->nuBit = false;
    this->metric = 0;
    this->prefixLen = 0;
}

OSPFv3InterAreaPrefixLSA::OSPFv3InterAreaPrefixLSA(const OSPFv3InterAreaPrefixLSA& other) : ::inet::OSPFv3LSA(other)
{
    copy(other);
}

OSPFv3InterAreaPrefixLSA::~OSPFv3InterAreaPrefixLSA()
{
}

OSPFv3InterAreaPrefixLSA& OSPFv3InterAreaPrefixLSA::operator=(const OSPFv3InterAreaPrefixLSA& other)
{
    if (this==&other) return *this;
    ::inet::OSPFv3LSA::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3InterAreaPrefixLSA::copy(const OSPFv3InterAreaPrefixLSA& other)
{
    this->dnBit = other.dnBit;
    this->pBit = other.pBit;
    this->xBit = other.xBit;
    this->laBit = other.laBit;
    this->nuBit = other.nuBit;
    this->metric = other.metric;
    this->prefixLen = other.prefixLen;
    this->prefix = other.prefix;
}

void OSPFv3InterAreaPrefixLSA::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::OSPFv3LSA::parsimPack(b);
    doParsimPacking(b,this->dnBit);
    doParsimPacking(b,this->pBit);
    doParsimPacking(b,this->xBit);
    doParsimPacking(b,this->laBit);
    doParsimPacking(b,this->nuBit);
    doParsimPacking(b,this->metric);
    doParsimPacking(b,this->prefixLen);
    doParsimPacking(b,this->prefix);
}

void OSPFv3InterAreaPrefixLSA::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::OSPFv3LSA::parsimUnpack(b);
    doParsimUnpacking(b,this->dnBit);
    doParsimUnpacking(b,this->pBit);
    doParsimUnpacking(b,this->xBit);
    doParsimUnpacking(b,this->laBit);
    doParsimUnpacking(b,this->nuBit);
    doParsimUnpacking(b,this->metric);
    doParsimUnpacking(b,this->prefixLen);
    doParsimUnpacking(b,this->prefix);
}

bool OSPFv3InterAreaPrefixLSA::getDnBit() const
{
    return this->dnBit;
}

void OSPFv3InterAreaPrefixLSA::setDnBit(bool dnBit)
{
    this->dnBit = dnBit;
}

bool OSPFv3InterAreaPrefixLSA::getPBit() const
{
    return this->pBit;
}

void OSPFv3InterAreaPrefixLSA::setPBit(bool pBit)
{
    this->pBit = pBit;
}

bool OSPFv3InterAreaPrefixLSA::getXBit() const
{
    return this->xBit;
}

void OSPFv3InterAreaPrefixLSA::setXBit(bool xBit)
{
    this->xBit = xBit;
}

bool OSPFv3InterAreaPrefixLSA::getLaBit() const
{
    return this->laBit;
}

void OSPFv3InterAreaPrefixLSA::setLaBit(bool laBit)
{
    this->laBit = laBit;
}

bool OSPFv3InterAreaPrefixLSA::getNuBit() const
{
    return this->nuBit;
}

void OSPFv3InterAreaPrefixLSA::setNuBit(bool nuBit)
{
    this->nuBit = nuBit;
}

uint32_t OSPFv3InterAreaPrefixLSA::getMetric() const
{
    return this->metric;
}

void OSPFv3InterAreaPrefixLSA::setMetric(uint32_t metric)
{
    this->metric = metric;
}

uint8_t OSPFv3InterAreaPrefixLSA::getPrefixLen() const
{
    return this->prefixLen;
}

void OSPFv3InterAreaPrefixLSA::setPrefixLen(uint8_t prefixLen)
{
    this->prefixLen = prefixLen;
}

L3Address& OSPFv3InterAreaPrefixLSA::getPrefix()
{
    return this->prefix;
}

void OSPFv3InterAreaPrefixLSA::setPrefix(const L3Address& prefix)
{
    this->prefix = prefix;
}

class OSPFv3InterAreaPrefixLSADescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3InterAreaPrefixLSADescriptor();
    virtual ~OSPFv3InterAreaPrefixLSADescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3InterAreaPrefixLSADescriptor);

OSPFv3InterAreaPrefixLSADescriptor::OSPFv3InterAreaPrefixLSADescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3InterAreaPrefixLSA", "inet::OSPFv3LSA")
{
    propertynames = nullptr;
}

OSPFv3InterAreaPrefixLSADescriptor::~OSPFv3InterAreaPrefixLSADescriptor()
{
    delete[] propertynames;
}

bool OSPFv3InterAreaPrefixLSADescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3InterAreaPrefixLSA *>(obj)!=nullptr;
}

const char **OSPFv3InterAreaPrefixLSADescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3InterAreaPrefixLSADescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3InterAreaPrefixLSADescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int OSPFv3InterAreaPrefixLSADescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3InterAreaPrefixLSADescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "dnBit",
        "pBit",
        "xBit",
        "laBit",
        "nuBit",
        "metric",
        "prefixLen",
        "prefix",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int OSPFv3InterAreaPrefixLSADescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dnBit")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pBit")==0) return base+1;
    if (fieldName[0]=='x' && strcmp(fieldName, "xBit")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "laBit")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "nuBit")==0) return base+4;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixLen")==0) return base+6;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefix")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3InterAreaPrefixLSADescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "uint32_t",
        "uint8_t",
        "L3Address",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3InterAreaPrefixLSADescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3InterAreaPrefixLSADescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3InterAreaPrefixLSADescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3InterAreaPrefixLSA *pp = (OSPFv3InterAreaPrefixLSA *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OSPFv3InterAreaPrefixLSADescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3InterAreaPrefixLSA *pp = (OSPFv3InterAreaPrefixLSA *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getDnBit());
        case 1: return bool2string(pp->getPBit());
        case 2: return bool2string(pp->getXBit());
        case 3: return bool2string(pp->getLaBit());
        case 4: return bool2string(pp->getNuBit());
        case 5: return ulong2string(pp->getMetric());
        case 6: return ulong2string(pp->getPrefixLen());
        case 7: {std::stringstream out; out << pp->getPrefix(); return out.str();}
        default: return "";
    }
}

bool OSPFv3InterAreaPrefixLSADescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3InterAreaPrefixLSA *pp = (OSPFv3InterAreaPrefixLSA *)object; (void)pp;
    switch (field) {
        case 0: pp->setDnBit(string2bool(value)); return true;
        case 1: pp->setPBit(string2bool(value)); return true;
        case 2: pp->setXBit(string2bool(value)); return true;
        case 3: pp->setLaBit(string2bool(value)); return true;
        case 4: pp->setNuBit(string2bool(value)); return true;
        case 5: pp->setMetric(string2ulong(value)); return true;
        case 6: pp->setPrefixLen(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFv3InterAreaPrefixLSADescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 7: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *OSPFv3InterAreaPrefixLSADescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3InterAreaPrefixLSA *pp = (OSPFv3InterAreaPrefixLSA *)object; (void)pp;
    switch (field) {
        case 7: return (void *)(&pp->getPrefix()); break;
        default: return nullptr;
    }
}

Register_Class(OSPFv3InterAreaRouterLSA);

OSPFv3InterAreaRouterLSA::OSPFv3InterAreaRouterLSA() : ::inet::OSPFv3LSA()
{
    this->metric = 0;
    this->destinationRouter = 0;
}

OSPFv3InterAreaRouterLSA::OSPFv3InterAreaRouterLSA(const OSPFv3InterAreaRouterLSA& other) : ::inet::OSPFv3LSA(other)
{
    copy(other);
}

OSPFv3InterAreaRouterLSA::~OSPFv3InterAreaRouterLSA()
{
}

OSPFv3InterAreaRouterLSA& OSPFv3InterAreaRouterLSA::operator=(const OSPFv3InterAreaRouterLSA& other)
{
    if (this==&other) return *this;
    ::inet::OSPFv3LSA::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3InterAreaRouterLSA::copy(const OSPFv3InterAreaRouterLSA& other)
{
    this->ospfOptions = other.ospfOptions;
    this->metric = other.metric;
    this->destinationRouter = other.destinationRouter;
}

void OSPFv3InterAreaRouterLSA::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::OSPFv3LSA::parsimPack(b);
    doParsimPacking(b,this->ospfOptions);
    doParsimPacking(b,this->metric);
    doParsimPacking(b,this->destinationRouter);
}

void OSPFv3InterAreaRouterLSA::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::OSPFv3LSA::parsimUnpack(b);
    doParsimUnpacking(b,this->ospfOptions);
    doParsimUnpacking(b,this->metric);
    doParsimUnpacking(b,this->destinationRouter);
}

OSPFv3Options& OSPFv3InterAreaRouterLSA::getOspfOptions()
{
    return this->ospfOptions;
}

void OSPFv3InterAreaRouterLSA::setOspfOptions(const OSPFv3Options& ospfOptions)
{
    this->ospfOptions = ospfOptions;
}

uint32_t OSPFv3InterAreaRouterLSA::getMetric() const
{
    return this->metric;
}

void OSPFv3InterAreaRouterLSA::setMetric(uint32_t metric)
{
    this->metric = metric;
}

uint32_t OSPFv3InterAreaRouterLSA::getDestinationRouter() const
{
    return this->destinationRouter;
}

void OSPFv3InterAreaRouterLSA::setDestinationRouter(uint32_t destinationRouter)
{
    this->destinationRouter = destinationRouter;
}

class OSPFv3InterAreaRouterLSADescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3InterAreaRouterLSADescriptor();
    virtual ~OSPFv3InterAreaRouterLSADescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3InterAreaRouterLSADescriptor);

OSPFv3InterAreaRouterLSADescriptor::OSPFv3InterAreaRouterLSADescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3InterAreaRouterLSA", "inet::OSPFv3LSA")
{
    propertynames = nullptr;
}

OSPFv3InterAreaRouterLSADescriptor::~OSPFv3InterAreaRouterLSADescriptor()
{
    delete[] propertynames;
}

bool OSPFv3InterAreaRouterLSADescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3InterAreaRouterLSA *>(obj)!=nullptr;
}

const char **OSPFv3InterAreaRouterLSADescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3InterAreaRouterLSADescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3InterAreaRouterLSADescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int OSPFv3InterAreaRouterLSADescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3InterAreaRouterLSADescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ospfOptions",
        "metric",
        "destinationRouter",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int OSPFv3InterAreaRouterLSADescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "ospfOptions")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationRouter")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3InterAreaRouterLSADescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "OSPFv3Options",
        "uint32_t",
        "uint32_t",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3InterAreaRouterLSADescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3InterAreaRouterLSADescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3InterAreaRouterLSADescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3InterAreaRouterLSA *pp = (OSPFv3InterAreaRouterLSA *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OSPFv3InterAreaRouterLSADescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3InterAreaRouterLSA *pp = (OSPFv3InterAreaRouterLSA *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getOspfOptions(); return out.str();}
        case 1: return ulong2string(pp->getMetric());
        case 2: return ulong2string(pp->getDestinationRouter());
        default: return "";
    }
}

bool OSPFv3InterAreaRouterLSADescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3InterAreaRouterLSA *pp = (OSPFv3InterAreaRouterLSA *)object; (void)pp;
    switch (field) {
        case 1: pp->setMetric(string2ulong(value)); return true;
        case 2: pp->setDestinationRouter(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFv3InterAreaRouterLSADescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(OSPFv3Options));
        default: return nullptr;
    };
}

void *OSPFv3InterAreaRouterLSADescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3InterAreaRouterLSA *pp = (OSPFv3InterAreaRouterLSA *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getOspfOptions()); break;
        default: return nullptr;
    }
}

Register_Class(OSPFv3ASExternalLSA);

OSPFv3ASExternalLSA::OSPFv3ASExternalLSA() : ::inet::OSPFv3LSA()
{
    this->eBit = false;
    this->fBit = false;
    this->tBit = false;
    this->metric = 0;
    this->referencedLSType = 0;
    this->externalRouteTag = 0;
    this->referencedLSID = 0;
}

OSPFv3ASExternalLSA::OSPFv3ASExternalLSA(const OSPFv3ASExternalLSA& other) : ::inet::OSPFv3LSA(other)
{
    copy(other);
}

OSPFv3ASExternalLSA::~OSPFv3ASExternalLSA()
{
}

OSPFv3ASExternalLSA& OSPFv3ASExternalLSA::operator=(const OSPFv3ASExternalLSA& other)
{
    if (this==&other) return *this;
    ::inet::OSPFv3LSA::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3ASExternalLSA::copy(const OSPFv3ASExternalLSA& other)
{
    this->eBit = other.eBit;
    this->fBit = other.fBit;
    this->tBit = other.tBit;
    this->metric = other.metric;
    this->referencedLSType = other.referencedLSType;
    this->forwardingAddress = other.forwardingAddress;
    this->externalRouteTag = other.externalRouteTag;
    this->referencedLSID = other.referencedLSID;
}

void OSPFv3ASExternalLSA::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::OSPFv3LSA::parsimPack(b);
    doParsimPacking(b,this->eBit);
    doParsimPacking(b,this->fBit);
    doParsimPacking(b,this->tBit);
    doParsimPacking(b,this->metric);
    doParsimPacking(b,this->referencedLSType);
    doParsimPacking(b,this->forwardingAddress);
    doParsimPacking(b,this->externalRouteTag);
    doParsimPacking(b,this->referencedLSID);
}

void OSPFv3ASExternalLSA::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::OSPFv3LSA::parsimUnpack(b);
    doParsimUnpacking(b,this->eBit);
    doParsimUnpacking(b,this->fBit);
    doParsimUnpacking(b,this->tBit);
    doParsimUnpacking(b,this->metric);
    doParsimUnpacking(b,this->referencedLSType);
    doParsimUnpacking(b,this->forwardingAddress);
    doParsimUnpacking(b,this->externalRouteTag);
    doParsimUnpacking(b,this->referencedLSID);
}

bool OSPFv3ASExternalLSA::getEBit() const
{
    return this->eBit;
}

void OSPFv3ASExternalLSA::setEBit(bool eBit)
{
    this->eBit = eBit;
}

bool OSPFv3ASExternalLSA::getFBit() const
{
    return this->fBit;
}

void OSPFv3ASExternalLSA::setFBit(bool fBit)
{
    this->fBit = fBit;
}

bool OSPFv3ASExternalLSA::getTBit() const
{
    return this->tBit;
}

void OSPFv3ASExternalLSA::setTBit(bool tBit)
{
    this->tBit = tBit;
}

uint32_t OSPFv3ASExternalLSA::getMetric() const
{
    return this->metric;
}

void OSPFv3ASExternalLSA::setMetric(uint32_t metric)
{
    this->metric = metric;
}

uint16_t OSPFv3ASExternalLSA::getReferencedLSType() const
{
    return this->referencedLSType;
}

void OSPFv3ASExternalLSA::setReferencedLSType(uint16_t referencedLSType)
{
    this->referencedLSType = referencedLSType;
}

IPv6Address& OSPFv3ASExternalLSA::getForwardingAddress()
{
    return this->forwardingAddress;
}

void OSPFv3ASExternalLSA::setForwardingAddress(const IPv6Address& forwardingAddress)
{
    this->forwardingAddress = forwardingAddress;
}

uint32_t OSPFv3ASExternalLSA::getExternalRouteTag() const
{
    return this->externalRouteTag;
}

void OSPFv3ASExternalLSA::setExternalRouteTag(uint32_t externalRouteTag)
{
    this->externalRouteTag = externalRouteTag;
}

uint32_t OSPFv3ASExternalLSA::getReferencedLSID() const
{
    return this->referencedLSID;
}

void OSPFv3ASExternalLSA::setReferencedLSID(uint32_t referencedLSID)
{
    this->referencedLSID = referencedLSID;
}

class OSPFv3ASExternalLSADescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3ASExternalLSADescriptor();
    virtual ~OSPFv3ASExternalLSADescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3ASExternalLSADescriptor);

OSPFv3ASExternalLSADescriptor::OSPFv3ASExternalLSADescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3ASExternalLSA", "inet::OSPFv3LSA")
{
    propertynames = nullptr;
}

OSPFv3ASExternalLSADescriptor::~OSPFv3ASExternalLSADescriptor()
{
    delete[] propertynames;
}

bool OSPFv3ASExternalLSADescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3ASExternalLSA *>(obj)!=nullptr;
}

const char **OSPFv3ASExternalLSADescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3ASExternalLSADescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3ASExternalLSADescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int OSPFv3ASExternalLSADescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3ASExternalLSADescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "eBit",
        "fBit",
        "tBit",
        "metric",
        "referencedLSType",
        "forwardingAddress",
        "externalRouteTag",
        "referencedLSID",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int OSPFv3ASExternalLSADescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "eBit")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fBit")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "tBit")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "referencedLSType")==0) return base+4;
    if (fieldName[0]=='f' && strcmp(fieldName, "forwardingAddress")==0) return base+5;
    if (fieldName[0]=='e' && strcmp(fieldName, "externalRouteTag")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "referencedLSID")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3ASExternalLSADescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "uint32_t",
        "uint16_t",
        "IPv6Address",
        "uint32_t",
        "uint32_t",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3ASExternalLSADescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3ASExternalLSADescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3ASExternalLSADescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3ASExternalLSA *pp = (OSPFv3ASExternalLSA *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OSPFv3ASExternalLSADescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3ASExternalLSA *pp = (OSPFv3ASExternalLSA *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getEBit());
        case 1: return bool2string(pp->getFBit());
        case 2: return bool2string(pp->getTBit());
        case 3: return ulong2string(pp->getMetric());
        case 4: return ulong2string(pp->getReferencedLSType());
        case 5: {std::stringstream out; out << pp->getForwardingAddress(); return out.str();}
        case 6: return ulong2string(pp->getExternalRouteTag());
        case 7: return ulong2string(pp->getReferencedLSID());
        default: return "";
    }
}

bool OSPFv3ASExternalLSADescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3ASExternalLSA *pp = (OSPFv3ASExternalLSA *)object; (void)pp;
    switch (field) {
        case 0: pp->setEBit(string2bool(value)); return true;
        case 1: pp->setFBit(string2bool(value)); return true;
        case 2: pp->setTBit(string2bool(value)); return true;
        case 3: pp->setMetric(string2ulong(value)); return true;
        case 4: pp->setReferencedLSType(string2ulong(value)); return true;
        case 6: pp->setExternalRouteTag(string2ulong(value)); return true;
        case 7: pp->setReferencedLSID(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFv3ASExternalLSADescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 5: return omnetpp::opp_typename(typeid(IPv6Address));
        default: return nullptr;
    };
}

void *OSPFv3ASExternalLSADescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3ASExternalLSA *pp = (OSPFv3ASExternalLSA *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getForwardingAddress()); break;
        default: return nullptr;
    }
}

Register_Class(OSPFv3NssaLSA);

OSPFv3NssaLSA::OSPFv3NssaLSA() : ::inet::OSPFv3LSA()
{
    this->eBit = false;
    this->fBit = false;
    this->tBit = false;
    this->metric = 0;
    this->referencedLSType = 0;
    this->externalRouteTag = 0;
    this->referencedLSID = 0;
}

OSPFv3NssaLSA::OSPFv3NssaLSA(const OSPFv3NssaLSA& other) : ::inet::OSPFv3LSA(other)
{
    copy(other);
}

OSPFv3NssaLSA::~OSPFv3NssaLSA()
{
}

OSPFv3NssaLSA& OSPFv3NssaLSA::operator=(const OSPFv3NssaLSA& other)
{
    if (this==&other) return *this;
    ::inet::OSPFv3LSA::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3NssaLSA::copy(const OSPFv3NssaLSA& other)
{
    this->eBit = other.eBit;
    this->fBit = other.fBit;
    this->tBit = other.tBit;
    this->metric = other.metric;
    this->prefOptions = other.prefOptions;
    this->referencedLSType = other.referencedLSType;
    this->forwardingAddress = other.forwardingAddress;
    this->externalRouteTag = other.externalRouteTag;
    this->referencedLSID = other.referencedLSID;
}

void OSPFv3NssaLSA::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::OSPFv3LSA::parsimPack(b);
    doParsimPacking(b,this->eBit);
    doParsimPacking(b,this->fBit);
    doParsimPacking(b,this->tBit);
    doParsimPacking(b,this->metric);
    doParsimPacking(b,this->prefOptions);
    doParsimPacking(b,this->referencedLSType);
    doParsimPacking(b,this->forwardingAddress);
    doParsimPacking(b,this->externalRouteTag);
    doParsimPacking(b,this->referencedLSID);
}

void OSPFv3NssaLSA::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::OSPFv3LSA::parsimUnpack(b);
    doParsimUnpacking(b,this->eBit);
    doParsimUnpacking(b,this->fBit);
    doParsimUnpacking(b,this->tBit);
    doParsimUnpacking(b,this->metric);
    doParsimUnpacking(b,this->prefOptions);
    doParsimUnpacking(b,this->referencedLSType);
    doParsimUnpacking(b,this->forwardingAddress);
    doParsimUnpacking(b,this->externalRouteTag);
    doParsimUnpacking(b,this->referencedLSID);
}

bool OSPFv3NssaLSA::getEBit() const
{
    return this->eBit;
}

void OSPFv3NssaLSA::setEBit(bool eBit)
{
    this->eBit = eBit;
}

bool OSPFv3NssaLSA::getFBit() const
{
    return this->fBit;
}

void OSPFv3NssaLSA::setFBit(bool fBit)
{
    this->fBit = fBit;
}

bool OSPFv3NssaLSA::getTBit() const
{
    return this->tBit;
}

void OSPFv3NssaLSA::setTBit(bool tBit)
{
    this->tBit = tBit;
}

uint32_t OSPFv3NssaLSA::getMetric() const
{
    return this->metric;
}

void OSPFv3NssaLSA::setMetric(uint32_t metric)
{
    this->metric = metric;
}

OSPFv3LSAPrefix& OSPFv3NssaLSA::getPrefOptions()
{
    return this->prefOptions;
}

void OSPFv3NssaLSA::setPrefOptions(const OSPFv3LSAPrefix& prefOptions)
{
    this->prefOptions = prefOptions;
}

uint16_t OSPFv3NssaLSA::getReferencedLSType() const
{
    return this->referencedLSType;
}

void OSPFv3NssaLSA::setReferencedLSType(uint16_t referencedLSType)
{
    this->referencedLSType = referencedLSType;
}

IPv6Address& OSPFv3NssaLSA::getForwardingAddress()
{
    return this->forwardingAddress;
}

void OSPFv3NssaLSA::setForwardingAddress(const IPv6Address& forwardingAddress)
{
    this->forwardingAddress = forwardingAddress;
}

uint32_t OSPFv3NssaLSA::getExternalRouteTag() const
{
    return this->externalRouteTag;
}

void OSPFv3NssaLSA::setExternalRouteTag(uint32_t externalRouteTag)
{
    this->externalRouteTag = externalRouteTag;
}

uint32_t OSPFv3NssaLSA::getReferencedLSID() const
{
    return this->referencedLSID;
}

void OSPFv3NssaLSA::setReferencedLSID(uint32_t referencedLSID)
{
    this->referencedLSID = referencedLSID;
}

class OSPFv3NssaLSADescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3NssaLSADescriptor();
    virtual ~OSPFv3NssaLSADescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3NssaLSADescriptor);

OSPFv3NssaLSADescriptor::OSPFv3NssaLSADescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3NssaLSA", "inet::OSPFv3LSA")
{
    propertynames = nullptr;
}

OSPFv3NssaLSADescriptor::~OSPFv3NssaLSADescriptor()
{
    delete[] propertynames;
}

bool OSPFv3NssaLSADescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3NssaLSA *>(obj)!=nullptr;
}

const char **OSPFv3NssaLSADescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3NssaLSADescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3NssaLSADescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int OSPFv3NssaLSADescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3NssaLSADescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "eBit",
        "fBit",
        "tBit",
        "metric",
        "prefOptions",
        "referencedLSType",
        "forwardingAddress",
        "externalRouteTag",
        "referencedLSID",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int OSPFv3NssaLSADescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "eBit")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fBit")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "tBit")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefOptions")==0) return base+4;
    if (fieldName[0]=='r' && strcmp(fieldName, "referencedLSType")==0) return base+5;
    if (fieldName[0]=='f' && strcmp(fieldName, "forwardingAddress")==0) return base+6;
    if (fieldName[0]=='e' && strcmp(fieldName, "externalRouteTag")==0) return base+7;
    if (fieldName[0]=='r' && strcmp(fieldName, "referencedLSID")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3NssaLSADescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "uint32_t",
        "OSPFv3LSAPrefix",
        "uint16_t",
        "IPv6Address",
        "uint32_t",
        "uint32_t",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3NssaLSADescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3NssaLSADescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3NssaLSADescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3NssaLSA *pp = (OSPFv3NssaLSA *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OSPFv3NssaLSADescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3NssaLSA *pp = (OSPFv3NssaLSA *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getEBit());
        case 1: return bool2string(pp->getFBit());
        case 2: return bool2string(pp->getTBit());
        case 3: return ulong2string(pp->getMetric());
        case 4: {std::stringstream out; out << pp->getPrefOptions(); return out.str();}
        case 5: return ulong2string(pp->getReferencedLSType());
        case 6: {std::stringstream out; out << pp->getForwardingAddress(); return out.str();}
        case 7: return ulong2string(pp->getExternalRouteTag());
        case 8: return ulong2string(pp->getReferencedLSID());
        default: return "";
    }
}

bool OSPFv3NssaLSADescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3NssaLSA *pp = (OSPFv3NssaLSA *)object; (void)pp;
    switch (field) {
        case 0: pp->setEBit(string2bool(value)); return true;
        case 1: pp->setFBit(string2bool(value)); return true;
        case 2: pp->setTBit(string2bool(value)); return true;
        case 3: pp->setMetric(string2ulong(value)); return true;
        case 5: pp->setReferencedLSType(string2ulong(value)); return true;
        case 7: pp->setExternalRouteTag(string2ulong(value)); return true;
        case 8: pp->setReferencedLSID(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFv3NssaLSADescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4: return omnetpp::opp_typename(typeid(OSPFv3LSAPrefix));
        case 6: return omnetpp::opp_typename(typeid(IPv6Address));
        default: return nullptr;
    };
}

void *OSPFv3NssaLSADescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3NssaLSA *pp = (OSPFv3NssaLSA *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->getPrefOptions()); break;
        case 6: return (void *)(&pp->getForwardingAddress()); break;
        default: return nullptr;
    }
}

Register_Class(OSPFv3LinkLSA);

OSPFv3LinkLSA::OSPFv3LinkLSA() : ::inet::OSPFv3LSA()
{
    this->routerPriority = 0;
    this->numPrefixes = 0;
    prefixes_arraysize = 0;
    this->prefixes = 0;
}

OSPFv3LinkLSA::OSPFv3LinkLSA(const OSPFv3LinkLSA& other) : ::inet::OSPFv3LSA(other)
{
    prefixes_arraysize = 0;
    this->prefixes = 0;
    copy(other);
}

OSPFv3LinkLSA::~OSPFv3LinkLSA()
{
    delete [] this->prefixes;
}

OSPFv3LinkLSA& OSPFv3LinkLSA::operator=(const OSPFv3LinkLSA& other)
{
    if (this==&other) return *this;
    ::inet::OSPFv3LSA::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3LinkLSA::copy(const OSPFv3LinkLSA& other)
{
    this->routerPriority = other.routerPriority;
    this->ospfOptions = other.ospfOptions;
    this->linkLocalInterfaceAdd = other.linkLocalInterfaceAdd;
    this->numPrefixes = other.numPrefixes;
    delete [] this->prefixes;
    this->prefixes = (other.prefixes_arraysize==0) ? nullptr : new OSPFv3LinkLSAPrefix[other.prefixes_arraysize];
    prefixes_arraysize = other.prefixes_arraysize;
    for (unsigned int i=0; i<prefixes_arraysize; i++)
        this->prefixes[i] = other.prefixes[i];
}

void OSPFv3LinkLSA::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::OSPFv3LSA::parsimPack(b);
    doParsimPacking(b,this->routerPriority);
    doParsimPacking(b,this->ospfOptions);
    doParsimPacking(b,this->linkLocalInterfaceAdd);
    doParsimPacking(b,this->numPrefixes);
    b->pack(prefixes_arraysize);
    doParsimArrayPacking(b,this->prefixes,prefixes_arraysize);
}

void OSPFv3LinkLSA::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::OSPFv3LSA::parsimUnpack(b);
    doParsimUnpacking(b,this->routerPriority);
    doParsimUnpacking(b,this->ospfOptions);
    doParsimUnpacking(b,this->linkLocalInterfaceAdd);
    doParsimUnpacking(b,this->numPrefixes);
    delete [] this->prefixes;
    b->unpack(prefixes_arraysize);
    if (prefixes_arraysize==0) {
        this->prefixes = 0;
    } else {
        this->prefixes = new OSPFv3LinkLSAPrefix[prefixes_arraysize];
        doParsimArrayUnpacking(b,this->prefixes,prefixes_arraysize);
    }
}

uint8_t OSPFv3LinkLSA::getRouterPriority() const
{
    return this->routerPriority;
}

void OSPFv3LinkLSA::setRouterPriority(uint8_t routerPriority)
{
    this->routerPriority = routerPriority;
}

OSPFv3Options& OSPFv3LinkLSA::getOspfOptions()
{
    return this->ospfOptions;
}

void OSPFv3LinkLSA::setOspfOptions(const OSPFv3Options& ospfOptions)
{
    this->ospfOptions = ospfOptions;
}

L3Address& OSPFv3LinkLSA::getLinkLocalInterfaceAdd()
{
    return this->linkLocalInterfaceAdd;
}

void OSPFv3LinkLSA::setLinkLocalInterfaceAdd(const L3Address& linkLocalInterfaceAdd)
{
    this->linkLocalInterfaceAdd = linkLocalInterfaceAdd;
}

uint32_t OSPFv3LinkLSA::getNumPrefixes() const
{
    return this->numPrefixes;
}

void OSPFv3LinkLSA::setNumPrefixes(uint32_t numPrefixes)
{
    this->numPrefixes = numPrefixes;
}

void OSPFv3LinkLSA::setPrefixesArraySize(unsigned int size)
{
    OSPFv3LinkLSAPrefix *prefixes2 = (size==0) ? nullptr : new OSPFv3LinkLSAPrefix[size];
    unsigned int sz = prefixes_arraysize < size ? prefixes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        prefixes2[i] = this->prefixes[i];
    prefixes_arraysize = size;
    delete [] this->prefixes;
    this->prefixes = prefixes2;
}

unsigned int OSPFv3LinkLSA::getPrefixesArraySize() const
{
    return prefixes_arraysize;
}

OSPFv3LinkLSAPrefix& OSPFv3LinkLSA::getPrefixes(unsigned int k)
{
    if (k>=prefixes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", prefixes_arraysize, k);
    return this->prefixes[k];
}

void OSPFv3LinkLSA::setPrefixes(unsigned int k, const OSPFv3LinkLSAPrefix& prefixes)
{
    if (k>=prefixes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", prefixes_arraysize, k);
    this->prefixes[k] = prefixes;
}

class OSPFv3LinkLSADescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3LinkLSADescriptor();
    virtual ~OSPFv3LinkLSADescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3LinkLSADescriptor);

OSPFv3LinkLSADescriptor::OSPFv3LinkLSADescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3LinkLSA", "inet::OSPFv3LSA")
{
    propertynames = nullptr;
}

OSPFv3LinkLSADescriptor::~OSPFv3LinkLSADescriptor()
{
    delete[] propertynames;
}

bool OSPFv3LinkLSADescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3LinkLSA *>(obj)!=nullptr;
}

const char **OSPFv3LinkLSADescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3LinkLSADescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3LinkLSADescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int OSPFv3LinkLSADescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3LinkLSADescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "routerPriority",
        "ospfOptions",
        "linkLocalInterfaceAdd",
        "numPrefixes",
        "prefixes",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int OSPFv3LinkLSADescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "routerPriority")==0) return base+0;
    if (fieldName[0]=='o' && strcmp(fieldName, "ospfOptions")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "linkLocalInterfaceAdd")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "numPrefixes")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixes")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3LinkLSADescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
        "OSPFv3Options",
        "L3Address",
        "uint32_t",
        "OSPFv3LinkLSAPrefix",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3LinkLSADescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3LinkLSADescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3LinkLSADescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LinkLSA *pp = (OSPFv3LinkLSA *)object; (void)pp;
    switch (field) {
        case 4: return pp->getPrefixesArraySize();
        default: return 0;
    }
}

std::string OSPFv3LinkLSADescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LinkLSA *pp = (OSPFv3LinkLSA *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getRouterPriority());
        case 1: {std::stringstream out; out << pp->getOspfOptions(); return out.str();}
        case 2: {std::stringstream out; out << pp->getLinkLocalInterfaceAdd(); return out.str();}
        case 3: return ulong2string(pp->getNumPrefixes());
        case 4: {std::stringstream out; out << pp->getPrefixes(i); return out.str();}
        default: return "";
    }
}

bool OSPFv3LinkLSADescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LinkLSA *pp = (OSPFv3LinkLSA *)object; (void)pp;
    switch (field) {
        case 0: pp->setRouterPriority(string2ulong(value)); return true;
        case 3: pp->setNumPrefixes(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFv3LinkLSADescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(OSPFv3Options));
        case 2: return omnetpp::opp_typename(typeid(L3Address));
        case 4: return omnetpp::opp_typename(typeid(OSPFv3LinkLSAPrefix));
        default: return nullptr;
    };
}

void *OSPFv3LinkLSADescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LinkLSA *pp = (OSPFv3LinkLSA *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getOspfOptions()); break;
        case 2: return (void *)(&pp->getLinkLocalInterfaceAdd()); break;
        case 4: return (void *)(&pp->getPrefixes(i)); break;
        default: return nullptr;
    }
}

Register_Class(OSPFv3IntraAreaPrefixLSA);

OSPFv3IntraAreaPrefixLSA::OSPFv3IntraAreaPrefixLSA() : ::inet::OSPFv3LSA()
{
    this->numPrefixes = 0;
    this->referencedLSType = 0;
    prefixes_arraysize = 0;
    this->prefixes = 0;
}

OSPFv3IntraAreaPrefixLSA::OSPFv3IntraAreaPrefixLSA(const OSPFv3IntraAreaPrefixLSA& other) : ::inet::OSPFv3LSA(other)
{
    prefixes_arraysize = 0;
    this->prefixes = 0;
    copy(other);
}

OSPFv3IntraAreaPrefixLSA::~OSPFv3IntraAreaPrefixLSA()
{
    delete [] this->prefixes;
}

OSPFv3IntraAreaPrefixLSA& OSPFv3IntraAreaPrefixLSA::operator=(const OSPFv3IntraAreaPrefixLSA& other)
{
    if (this==&other) return *this;
    ::inet::OSPFv3LSA::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3IntraAreaPrefixLSA::copy(const OSPFv3IntraAreaPrefixLSA& other)
{
    this->numPrefixes = other.numPrefixes;
    this->referencedLSType = other.referencedLSType;
    this->referencedLSID = other.referencedLSID;
    this->referencedAdvRtr = other.referencedAdvRtr;
    delete [] this->prefixes;
    this->prefixes = (other.prefixes_arraysize==0) ? nullptr : new OSPFv3LSAPrefix[other.prefixes_arraysize];
    prefixes_arraysize = other.prefixes_arraysize;
    for (unsigned int i=0; i<prefixes_arraysize; i++)
        this->prefixes[i] = other.prefixes[i];
}

void OSPFv3IntraAreaPrefixLSA::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::OSPFv3LSA::parsimPack(b);
    doParsimPacking(b,this->numPrefixes);
    doParsimPacking(b,this->referencedLSType);
    doParsimPacking(b,this->referencedLSID);
    doParsimPacking(b,this->referencedAdvRtr);
    b->pack(prefixes_arraysize);
    doParsimArrayPacking(b,this->prefixes,prefixes_arraysize);
}

void OSPFv3IntraAreaPrefixLSA::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::OSPFv3LSA::parsimUnpack(b);
    doParsimUnpacking(b,this->numPrefixes);
    doParsimUnpacking(b,this->referencedLSType);
    doParsimUnpacking(b,this->referencedLSID);
    doParsimUnpacking(b,this->referencedAdvRtr);
    delete [] this->prefixes;
    b->unpack(prefixes_arraysize);
    if (prefixes_arraysize==0) {
        this->prefixes = 0;
    } else {
        this->prefixes = new OSPFv3LSAPrefix[prefixes_arraysize];
        doParsimArrayUnpacking(b,this->prefixes,prefixes_arraysize);
    }
}

uint16_t OSPFv3IntraAreaPrefixLSA::getNumPrefixes() const
{
    return this->numPrefixes;
}

void OSPFv3IntraAreaPrefixLSA::setNumPrefixes(uint16_t numPrefixes)
{
    this->numPrefixes = numPrefixes;
}

uint16_t OSPFv3IntraAreaPrefixLSA::getReferencedLSType() const
{
    return this->referencedLSType;
}

void OSPFv3IntraAreaPrefixLSA::setReferencedLSType(uint16_t referencedLSType)
{
    this->referencedLSType = referencedLSType;
}

IPv4Address& OSPFv3IntraAreaPrefixLSA::getReferencedLSID()
{
    return this->referencedLSID;
}

void OSPFv3IntraAreaPrefixLSA::setReferencedLSID(const IPv4Address& referencedLSID)
{
    this->referencedLSID = referencedLSID;
}

IPv4Address& OSPFv3IntraAreaPrefixLSA::getReferencedAdvRtr()
{
    return this->referencedAdvRtr;
}

void OSPFv3IntraAreaPrefixLSA::setReferencedAdvRtr(const IPv4Address& referencedAdvRtr)
{
    this->referencedAdvRtr = referencedAdvRtr;
}

void OSPFv3IntraAreaPrefixLSA::setPrefixesArraySize(unsigned int size)
{
    OSPFv3LSAPrefix *prefixes2 = (size==0) ? nullptr : new OSPFv3LSAPrefix[size];
    unsigned int sz = prefixes_arraysize < size ? prefixes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        prefixes2[i] = this->prefixes[i];
    prefixes_arraysize = size;
    delete [] this->prefixes;
    this->prefixes = prefixes2;
}

unsigned int OSPFv3IntraAreaPrefixLSA::getPrefixesArraySize() const
{
    return prefixes_arraysize;
}

OSPFv3LSAPrefix& OSPFv3IntraAreaPrefixLSA::getPrefixes(unsigned int k)
{
    if (k>=prefixes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", prefixes_arraysize, k);
    return this->prefixes[k];
}

void OSPFv3IntraAreaPrefixLSA::setPrefixes(unsigned int k, const OSPFv3LSAPrefix& prefixes)
{
    if (k>=prefixes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", prefixes_arraysize, k);
    this->prefixes[k] = prefixes;
}

class OSPFv3IntraAreaPrefixLSADescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3IntraAreaPrefixLSADescriptor();
    virtual ~OSPFv3IntraAreaPrefixLSADescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3IntraAreaPrefixLSADescriptor);

OSPFv3IntraAreaPrefixLSADescriptor::OSPFv3IntraAreaPrefixLSADescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3IntraAreaPrefixLSA", "inet::OSPFv3LSA")
{
    propertynames = nullptr;
}

OSPFv3IntraAreaPrefixLSADescriptor::~OSPFv3IntraAreaPrefixLSADescriptor()
{
    delete[] propertynames;
}

bool OSPFv3IntraAreaPrefixLSADescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3IntraAreaPrefixLSA *>(obj)!=nullptr;
}

const char **OSPFv3IntraAreaPrefixLSADescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3IntraAreaPrefixLSADescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3IntraAreaPrefixLSADescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int OSPFv3IntraAreaPrefixLSADescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3IntraAreaPrefixLSADescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "numPrefixes",
        "referencedLSType",
        "referencedLSID",
        "referencedAdvRtr",
        "prefixes",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int OSPFv3IntraAreaPrefixLSADescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numPrefixes")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "referencedLSType")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "referencedLSID")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "referencedAdvRtr")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixes")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3IntraAreaPrefixLSADescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",
        "uint16_t",
        "IPv4Address",
        "IPv4Address",
        "OSPFv3LSAPrefix",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3IntraAreaPrefixLSADescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3IntraAreaPrefixLSADescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3IntraAreaPrefixLSADescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3IntraAreaPrefixLSA *pp = (OSPFv3IntraAreaPrefixLSA *)object; (void)pp;
    switch (field) {
        case 4: return pp->getPrefixesArraySize();
        default: return 0;
    }
}

std::string OSPFv3IntraAreaPrefixLSADescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3IntraAreaPrefixLSA *pp = (OSPFv3IntraAreaPrefixLSA *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getNumPrefixes());
        case 1: return ulong2string(pp->getReferencedLSType());
        case 2: {std::stringstream out; out << pp->getReferencedLSID(); return out.str();}
        case 3: {std::stringstream out; out << pp->getReferencedAdvRtr(); return out.str();}
        case 4: {std::stringstream out; out << pp->getPrefixes(i); return out.str();}
        default: return "";
    }
}

bool OSPFv3IntraAreaPrefixLSADescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3IntraAreaPrefixLSA *pp = (OSPFv3IntraAreaPrefixLSA *)object; (void)pp;
    switch (field) {
        case 0: pp->setNumPrefixes(string2ulong(value)); return true;
        case 1: pp->setReferencedLSType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFv3IntraAreaPrefixLSADescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(IPv4Address));
        case 3: return omnetpp::opp_typename(typeid(IPv4Address));
        case 4: return omnetpp::opp_typename(typeid(OSPFv3LSAPrefix));
        default: return nullptr;
    };
}

void *OSPFv3IntraAreaPrefixLSADescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3IntraAreaPrefixLSA *pp = (OSPFv3IntraAreaPrefixLSA *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getReferencedLSID()); break;
        case 3: return (void *)(&pp->getReferencedAdvRtr()); break;
        case 4: return (void *)(&pp->getPrefixes(i)); break;
        default: return nullptr;
    }
}

OSPFv3DDOptions::OSPFv3DDOptions()
{
    this->iBit = false;
    this->mBit = false;
    this->msBit = false;
}

void __doPacking(omnetpp::cCommBuffer *b, const OSPFv3DDOptions& a)
{
    doParsimPacking(b,a.iBit);
    doParsimPacking(b,a.mBit);
    doParsimPacking(b,a.msBit);
}

void __doUnpacking(omnetpp::cCommBuffer *b, OSPFv3DDOptions& a)
{
    doParsimUnpacking(b,a.iBit);
    doParsimUnpacking(b,a.mBit);
    doParsimUnpacking(b,a.msBit);
}

class OSPFv3DDOptionsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3DDOptionsDescriptor();
    virtual ~OSPFv3DDOptionsDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3DDOptionsDescriptor);

OSPFv3DDOptionsDescriptor::OSPFv3DDOptionsDescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3DDOptions", "")
{
    propertynames = nullptr;
}

OSPFv3DDOptionsDescriptor::~OSPFv3DDOptionsDescriptor()
{
    delete[] propertynames;
}

bool OSPFv3DDOptionsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3DDOptions *>(obj)!=nullptr;
}

const char **OSPFv3DDOptionsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3DDOptionsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3DDOptionsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int OSPFv3DDOptionsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3DDOptionsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "iBit",
        "mBit",
        "msBit",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int OSPFv3DDOptionsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "iBit")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "mBit")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "msBit")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3DDOptionsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3DDOptionsDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3DDOptionsDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3DDOptionsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3DDOptions *pp = (OSPFv3DDOptions *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OSPFv3DDOptionsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3DDOptions *pp = (OSPFv3DDOptions *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->iBit);
        case 1: return bool2string(pp->mBit);
        case 2: return bool2string(pp->msBit);
        default: return "";
    }
}

bool OSPFv3DDOptionsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3DDOptions *pp = (OSPFv3DDOptions *)object; (void)pp;
    switch (field) {
        case 0: pp->iBit = string2bool(value); return true;
        case 1: pp->mBit = string2bool(value); return true;
        case 2: pp->msBit = string2bool(value); return true;
        default: return false;
    }
}

const char *OSPFv3DDOptionsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *OSPFv3DDOptionsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3DDOptions *pp = (OSPFv3DDOptions *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(OSPFv3DatabaseDescription);

OSPFv3DatabaseDescription::OSPFv3DatabaseDescription(const char *name, int kind) : ::inet::OSPFv3Packet(name,kind)
{
    this->interfaceMTU = 0;
    this->sequenceNumber = 0;
    lsaHeaders_arraysize = 0;
    this->lsaHeaders = 0;
}

OSPFv3DatabaseDescription::OSPFv3DatabaseDescription(const OSPFv3DatabaseDescription& other) : ::inet::OSPFv3Packet(other)
{
    lsaHeaders_arraysize = 0;
    this->lsaHeaders = 0;
    copy(other);
}

OSPFv3DatabaseDescription::~OSPFv3DatabaseDescription()
{
    delete [] this->lsaHeaders;
}

OSPFv3DatabaseDescription& OSPFv3DatabaseDescription::operator=(const OSPFv3DatabaseDescription& other)
{
    if (this==&other) return *this;
    ::inet::OSPFv3Packet::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3DatabaseDescription::copy(const OSPFv3DatabaseDescription& other)
{
    this->options = other.options;
    this->interfaceMTU = other.interfaceMTU;
    this->ddOptions = other.ddOptions;
    this->sequenceNumber = other.sequenceNumber;
    delete [] this->lsaHeaders;
    this->lsaHeaders = (other.lsaHeaders_arraysize==0) ? nullptr : new OSPFv3LSAHeader[other.lsaHeaders_arraysize];
    lsaHeaders_arraysize = other.lsaHeaders_arraysize;
    for (unsigned int i=0; i<lsaHeaders_arraysize; i++)
        this->lsaHeaders[i] = other.lsaHeaders[i];
}

void OSPFv3DatabaseDescription::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::OSPFv3Packet::parsimPack(b);
    doParsimPacking(b,this->options);
    doParsimPacking(b,this->interfaceMTU);
    doParsimPacking(b,this->ddOptions);
    doParsimPacking(b,this->sequenceNumber);
    b->pack(lsaHeaders_arraysize);
    doParsimArrayPacking(b,this->lsaHeaders,lsaHeaders_arraysize);
}

void OSPFv3DatabaseDescription::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::OSPFv3Packet::parsimUnpack(b);
    doParsimUnpacking(b,this->options);
    doParsimUnpacking(b,this->interfaceMTU);
    doParsimUnpacking(b,this->ddOptions);
    doParsimUnpacking(b,this->sequenceNumber);
    delete [] this->lsaHeaders;
    b->unpack(lsaHeaders_arraysize);
    if (lsaHeaders_arraysize==0) {
        this->lsaHeaders = 0;
    } else {
        this->lsaHeaders = new OSPFv3LSAHeader[lsaHeaders_arraysize];
        doParsimArrayUnpacking(b,this->lsaHeaders,lsaHeaders_arraysize);
    }
}

OSPFv3Options& OSPFv3DatabaseDescription::getOptions()
{
    return this->options;
}

void OSPFv3DatabaseDescription::setOptions(const OSPFv3Options& options)
{
    this->options = options;
}

uint16_t OSPFv3DatabaseDescription::getInterfaceMTU() const
{
    return this->interfaceMTU;
}

void OSPFv3DatabaseDescription::setInterfaceMTU(uint16_t interfaceMTU)
{
    this->interfaceMTU = interfaceMTU;
}

OSPFv3DDOptions& OSPFv3DatabaseDescription::getDdOptions()
{
    return this->ddOptions;
}

void OSPFv3DatabaseDescription::setDdOptions(const OSPFv3DDOptions& ddOptions)
{
    this->ddOptions = ddOptions;
}

uint32_t OSPFv3DatabaseDescription::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void OSPFv3DatabaseDescription::setSequenceNumber(uint32_t sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

void OSPFv3DatabaseDescription::setLsaHeadersArraySize(unsigned int size)
{
    OSPFv3LSAHeader *lsaHeaders2 = (size==0) ? nullptr : new OSPFv3LSAHeader[size];
    unsigned int sz = lsaHeaders_arraysize < size ? lsaHeaders_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        lsaHeaders2[i] = this->lsaHeaders[i];
    lsaHeaders_arraysize = size;
    delete [] this->lsaHeaders;
    this->lsaHeaders = lsaHeaders2;
}

unsigned int OSPFv3DatabaseDescription::getLsaHeadersArraySize() const
{
    return lsaHeaders_arraysize;
}

OSPFv3LSAHeader& OSPFv3DatabaseDescription::getLsaHeaders(unsigned int k)
{
    if (k>=lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", lsaHeaders_arraysize, k);
    return this->lsaHeaders[k];
}

void OSPFv3DatabaseDescription::setLsaHeaders(unsigned int k, const OSPFv3LSAHeader& lsaHeaders)
{
    if (k>=lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", lsaHeaders_arraysize, k);
    this->lsaHeaders[k] = lsaHeaders;
}

class OSPFv3DatabaseDescriptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3DatabaseDescriptionDescriptor();
    virtual ~OSPFv3DatabaseDescriptionDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3DatabaseDescriptionDescriptor);

OSPFv3DatabaseDescriptionDescriptor::OSPFv3DatabaseDescriptionDescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3DatabaseDescription", "inet::OSPFv3Packet")
{
    propertynames = nullptr;
}

OSPFv3DatabaseDescriptionDescriptor::~OSPFv3DatabaseDescriptionDescriptor()
{
    delete[] propertynames;
}

bool OSPFv3DatabaseDescriptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3DatabaseDescription *>(obj)!=nullptr;
}

const char **OSPFv3DatabaseDescriptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3DatabaseDescriptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3DatabaseDescriptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int OSPFv3DatabaseDescriptionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3DatabaseDescriptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "options",
        "interfaceMTU",
        "ddOptions",
        "sequenceNumber",
        "lsaHeaders",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int OSPFv3DatabaseDescriptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "options")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceMTU")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "ddOptions")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNumber")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsaHeaders")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3DatabaseDescriptionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "OSPFv3Options",
        "uint16_t",
        "OSPFv3DDOptions",
        "uint32_t",
        "OSPFv3LSAHeader",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3DatabaseDescriptionDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3DatabaseDescriptionDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3DatabaseDescriptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3DatabaseDescription *pp = (OSPFv3DatabaseDescription *)object; (void)pp;
    switch (field) {
        case 4: return pp->getLsaHeadersArraySize();
        default: return 0;
    }
}

std::string OSPFv3DatabaseDescriptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3DatabaseDescription *pp = (OSPFv3DatabaseDescription *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getOptions(); return out.str();}
        case 1: return ulong2string(pp->getInterfaceMTU());
        case 2: {std::stringstream out; out << pp->getDdOptions(); return out.str();}
        case 3: return ulong2string(pp->getSequenceNumber());
        case 4: {std::stringstream out; out << pp->getLsaHeaders(i); return out.str();}
        default: return "";
    }
}

bool OSPFv3DatabaseDescriptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3DatabaseDescription *pp = (OSPFv3DatabaseDescription *)object; (void)pp;
    switch (field) {
        case 1: pp->setInterfaceMTU(string2ulong(value)); return true;
        case 3: pp->setSequenceNumber(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFv3DatabaseDescriptionDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(OSPFv3Options));
        case 2: return omnetpp::opp_typename(typeid(OSPFv3DDOptions));
        case 4: return omnetpp::opp_typename(typeid(OSPFv3LSAHeader));
        default: return nullptr;
    };
}

void *OSPFv3DatabaseDescriptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3DatabaseDescription *pp = (OSPFv3DatabaseDescription *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getOptions()); break;
        case 2: return (void *)(&pp->getDdOptions()); break;
        case 4: return (void *)static_cast<omnetpp::cObject *>(&pp->getLsaHeaders(i)); break;
        default: return nullptr;
    }
}

OSPFv3LSRequest::OSPFv3LSRequest()
{
    this->lsaType = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const OSPFv3LSRequest& a)
{
    doParsimPacking(b,a.lsaType);
    doParsimPacking(b,a.lsaID);
    doParsimPacking(b,a.advertisingRouter);
}

void __doUnpacking(omnetpp::cCommBuffer *b, OSPFv3LSRequest& a)
{
    doParsimUnpacking(b,a.lsaType);
    doParsimUnpacking(b,a.lsaID);
    doParsimUnpacking(b,a.advertisingRouter);
}

class OSPFv3LSRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3LSRequestDescriptor();
    virtual ~OSPFv3LSRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3LSRequestDescriptor);

OSPFv3LSRequestDescriptor::OSPFv3LSRequestDescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3LSRequest", "")
{
    propertynames = nullptr;
}

OSPFv3LSRequestDescriptor::~OSPFv3LSRequestDescriptor()
{
    delete[] propertynames;
}

bool OSPFv3LSRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3LSRequest *>(obj)!=nullptr;
}

const char **OSPFv3LSRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3LSRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3LSRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int OSPFv3LSRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3LSRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lsaType",
        "lsaID",
        "advertisingRouter",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int OSPFv3LSRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsaType")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsaID")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "advertisingRouter")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3LSRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",
        "IPv4Address",
        "IPv4Address",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3LSRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3LSRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3LSRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSRequest *pp = (OSPFv3LSRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OSPFv3LSRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSRequest *pp = (OSPFv3LSRequest *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->lsaType);
        case 1: {std::stringstream out; out << pp->lsaID; return out.str();}
        case 2: {std::stringstream out; out << pp->advertisingRouter; return out.str();}
        default: return "";
    }
}

bool OSPFv3LSRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSRequest *pp = (OSPFv3LSRequest *)object; (void)pp;
    switch (field) {
        case 0: pp->lsaType = string2ulong(value); return true;
        default: return false;
    }
}

const char *OSPFv3LSRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(IPv4Address));
        case 2: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *OSPFv3LSRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSRequest *pp = (OSPFv3LSRequest *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->lsaID); break;
        case 2: return (void *)(&pp->advertisingRouter); break;
        default: return nullptr;
    }
}

Register_Class(OSPFv3LinkStateRequest);

OSPFv3LinkStateRequest::OSPFv3LinkStateRequest(const char *name, int kind) : ::inet::OSPFv3Packet(name,kind)
{
    requests_arraysize = 0;
    this->requests = 0;
}

OSPFv3LinkStateRequest::OSPFv3LinkStateRequest(const OSPFv3LinkStateRequest& other) : ::inet::OSPFv3Packet(other)
{
    requests_arraysize = 0;
    this->requests = 0;
    copy(other);
}

OSPFv3LinkStateRequest::~OSPFv3LinkStateRequest()
{
    delete [] this->requests;
}

OSPFv3LinkStateRequest& OSPFv3LinkStateRequest::operator=(const OSPFv3LinkStateRequest& other)
{
    if (this==&other) return *this;
    ::inet::OSPFv3Packet::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3LinkStateRequest::copy(const OSPFv3LinkStateRequest& other)
{
    delete [] this->requests;
    this->requests = (other.requests_arraysize==0) ? nullptr : new OSPFv3LSRequest[other.requests_arraysize];
    requests_arraysize = other.requests_arraysize;
    for (unsigned int i=0; i<requests_arraysize; i++)
        this->requests[i] = other.requests[i];
}

void OSPFv3LinkStateRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::OSPFv3Packet::parsimPack(b);
    b->pack(requests_arraysize);
    doParsimArrayPacking(b,this->requests,requests_arraysize);
}

void OSPFv3LinkStateRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::OSPFv3Packet::parsimUnpack(b);
    delete [] this->requests;
    b->unpack(requests_arraysize);
    if (requests_arraysize==0) {
        this->requests = 0;
    } else {
        this->requests = new OSPFv3LSRequest[requests_arraysize];
        doParsimArrayUnpacking(b,this->requests,requests_arraysize);
    }
}

void OSPFv3LinkStateRequest::setRequestsArraySize(unsigned int size)
{
    OSPFv3LSRequest *requests2 = (size==0) ? nullptr : new OSPFv3LSRequest[size];
    unsigned int sz = requests_arraysize < size ? requests_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        requests2[i] = this->requests[i];
    requests_arraysize = size;
    delete [] this->requests;
    this->requests = requests2;
}

unsigned int OSPFv3LinkStateRequest::getRequestsArraySize() const
{
    return requests_arraysize;
}

OSPFv3LSRequest& OSPFv3LinkStateRequest::getRequests(unsigned int k)
{
    if (k>=requests_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", requests_arraysize, k);
    return this->requests[k];
}

void OSPFv3LinkStateRequest::setRequests(unsigned int k, const OSPFv3LSRequest& requests)
{
    if (k>=requests_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", requests_arraysize, k);
    this->requests[k] = requests;
}

class OSPFv3LinkStateRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3LinkStateRequestDescriptor();
    virtual ~OSPFv3LinkStateRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3LinkStateRequestDescriptor);

OSPFv3LinkStateRequestDescriptor::OSPFv3LinkStateRequestDescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3LinkStateRequest", "inet::OSPFv3Packet")
{
    propertynames = nullptr;
}

OSPFv3LinkStateRequestDescriptor::~OSPFv3LinkStateRequestDescriptor()
{
    delete[] propertynames;
}

bool OSPFv3LinkStateRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3LinkStateRequest *>(obj)!=nullptr;
}

const char **OSPFv3LinkStateRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3LinkStateRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3LinkStateRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int OSPFv3LinkStateRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3LinkStateRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "requests",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int OSPFv3LinkStateRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "requests")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3LinkStateRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "OSPFv3LSRequest",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3LinkStateRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3LinkStateRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3LinkStateRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LinkStateRequest *pp = (OSPFv3LinkStateRequest *)object; (void)pp;
    switch (field) {
        case 0: return pp->getRequestsArraySize();
        default: return 0;
    }
}

std::string OSPFv3LinkStateRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LinkStateRequest *pp = (OSPFv3LinkStateRequest *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRequests(i); return out.str();}
        default: return "";
    }
}

bool OSPFv3LinkStateRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LinkStateRequest *pp = (OSPFv3LinkStateRequest *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OSPFv3LinkStateRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(OSPFv3LSRequest));
        default: return nullptr;
    };
}

void *OSPFv3LinkStateRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LinkStateRequest *pp = (OSPFv3LinkStateRequest *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getRequests(i)); break;
        default: return nullptr;
    }
}

Register_Class(OSPFv3LSUpdate);

OSPFv3LSUpdate::OSPFv3LSUpdate(const char *name, int kind) : ::inet::OSPFv3Packet(name,kind)
{
    this->lsaCount = 0;
    RouterLSAs_arraysize = 0;
    this->RouterLSAs = 0;
    NetworkLSAs_arraysize = 0;
    this->NetworkLSAs = 0;
    InterAreaPrefixLSAs_arraysize = 0;
    this->InterAreaPrefixLSAs = 0;
    LinkLSAs_arraysize = 0;
    this->LinkLSAs = 0;
    IntraAreaPrefixLSAs_arraysize = 0;
    this->IntraAreaPrefixLSAs = 0;
}

OSPFv3LSUpdate::OSPFv3LSUpdate(const OSPFv3LSUpdate& other) : ::inet::OSPFv3Packet(other)
{
    RouterLSAs_arraysize = 0;
    this->RouterLSAs = 0;
    NetworkLSAs_arraysize = 0;
    this->NetworkLSAs = 0;
    InterAreaPrefixLSAs_arraysize = 0;
    this->InterAreaPrefixLSAs = 0;
    LinkLSAs_arraysize = 0;
    this->LinkLSAs = 0;
    IntraAreaPrefixLSAs_arraysize = 0;
    this->IntraAreaPrefixLSAs = 0;
    copy(other);
}

OSPFv3LSUpdate::~OSPFv3LSUpdate()
{
    delete [] this->RouterLSAs;
    delete [] this->NetworkLSAs;
    delete [] this->InterAreaPrefixLSAs;
    delete [] this->LinkLSAs;
    delete [] this->IntraAreaPrefixLSAs;
}

OSPFv3LSUpdate& OSPFv3LSUpdate::operator=(const OSPFv3LSUpdate& other)
{
    if (this==&other) return *this;
    ::inet::OSPFv3Packet::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3LSUpdate::copy(const OSPFv3LSUpdate& other)
{
    this->lsaCount = other.lsaCount;
    delete [] this->RouterLSAs;
    this->RouterLSAs = (other.RouterLSAs_arraysize==0) ? nullptr : new OSPFv3RouterLSA[other.RouterLSAs_arraysize];
    RouterLSAs_arraysize = other.RouterLSAs_arraysize;
    for (unsigned int i=0; i<RouterLSAs_arraysize; i++)
        this->RouterLSAs[i] = other.RouterLSAs[i];
    delete [] this->NetworkLSAs;
    this->NetworkLSAs = (other.NetworkLSAs_arraysize==0) ? nullptr : new OSPFv3NetworkLSA[other.NetworkLSAs_arraysize];
    NetworkLSAs_arraysize = other.NetworkLSAs_arraysize;
    for (unsigned int i=0; i<NetworkLSAs_arraysize; i++)
        this->NetworkLSAs[i] = other.NetworkLSAs[i];
    delete [] this->InterAreaPrefixLSAs;
    this->InterAreaPrefixLSAs = (other.InterAreaPrefixLSAs_arraysize==0) ? nullptr : new OSPFv3InterAreaPrefixLSA[other.InterAreaPrefixLSAs_arraysize];
    InterAreaPrefixLSAs_arraysize = other.InterAreaPrefixLSAs_arraysize;
    for (unsigned int i=0; i<InterAreaPrefixLSAs_arraysize; i++)
        this->InterAreaPrefixLSAs[i] = other.InterAreaPrefixLSAs[i];
    delete [] this->LinkLSAs;
    this->LinkLSAs = (other.LinkLSAs_arraysize==0) ? nullptr : new OSPFv3LinkLSA[other.LinkLSAs_arraysize];
    LinkLSAs_arraysize = other.LinkLSAs_arraysize;
    for (unsigned int i=0; i<LinkLSAs_arraysize; i++)
        this->LinkLSAs[i] = other.LinkLSAs[i];
    delete [] this->IntraAreaPrefixLSAs;
    this->IntraAreaPrefixLSAs = (other.IntraAreaPrefixLSAs_arraysize==0) ? nullptr : new OSPFv3IntraAreaPrefixLSA[other.IntraAreaPrefixLSAs_arraysize];
    IntraAreaPrefixLSAs_arraysize = other.IntraAreaPrefixLSAs_arraysize;
    for (unsigned int i=0; i<IntraAreaPrefixLSAs_arraysize; i++)
        this->IntraAreaPrefixLSAs[i] = other.IntraAreaPrefixLSAs[i];
}

void OSPFv3LSUpdate::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::OSPFv3Packet::parsimPack(b);
    doParsimPacking(b,this->lsaCount);
    b->pack(RouterLSAs_arraysize);
    doParsimArrayPacking(b,this->RouterLSAs,RouterLSAs_arraysize);
    b->pack(NetworkLSAs_arraysize);
    doParsimArrayPacking(b,this->NetworkLSAs,NetworkLSAs_arraysize);
    b->pack(InterAreaPrefixLSAs_arraysize);
    doParsimArrayPacking(b,this->InterAreaPrefixLSAs,InterAreaPrefixLSAs_arraysize);
    b->pack(LinkLSAs_arraysize);
    doParsimArrayPacking(b,this->LinkLSAs,LinkLSAs_arraysize);
    b->pack(IntraAreaPrefixLSAs_arraysize);
    doParsimArrayPacking(b,this->IntraAreaPrefixLSAs,IntraAreaPrefixLSAs_arraysize);
}

void OSPFv3LSUpdate::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::OSPFv3Packet::parsimUnpack(b);
    doParsimUnpacking(b,this->lsaCount);
    delete [] this->RouterLSAs;
    b->unpack(RouterLSAs_arraysize);
    if (RouterLSAs_arraysize==0) {
        this->RouterLSAs = 0;
    } else {
        this->RouterLSAs = new OSPFv3RouterLSA[RouterLSAs_arraysize];
        doParsimArrayUnpacking(b,this->RouterLSAs,RouterLSAs_arraysize);
    }
    delete [] this->NetworkLSAs;
    b->unpack(NetworkLSAs_arraysize);
    if (NetworkLSAs_arraysize==0) {
        this->NetworkLSAs = 0;
    } else {
        this->NetworkLSAs = new OSPFv3NetworkLSA[NetworkLSAs_arraysize];
        doParsimArrayUnpacking(b,this->NetworkLSAs,NetworkLSAs_arraysize);
    }
    delete [] this->InterAreaPrefixLSAs;
    b->unpack(InterAreaPrefixLSAs_arraysize);
    if (InterAreaPrefixLSAs_arraysize==0) {
        this->InterAreaPrefixLSAs = 0;
    } else {
        this->InterAreaPrefixLSAs = new OSPFv3InterAreaPrefixLSA[InterAreaPrefixLSAs_arraysize];
        doParsimArrayUnpacking(b,this->InterAreaPrefixLSAs,InterAreaPrefixLSAs_arraysize);
    }
    delete [] this->LinkLSAs;
    b->unpack(LinkLSAs_arraysize);
    if (LinkLSAs_arraysize==0) {
        this->LinkLSAs = 0;
    } else {
        this->LinkLSAs = new OSPFv3LinkLSA[LinkLSAs_arraysize];
        doParsimArrayUnpacking(b,this->LinkLSAs,LinkLSAs_arraysize);
    }
    delete [] this->IntraAreaPrefixLSAs;
    b->unpack(IntraAreaPrefixLSAs_arraysize);
    if (IntraAreaPrefixLSAs_arraysize==0) {
        this->IntraAreaPrefixLSAs = 0;
    } else {
        this->IntraAreaPrefixLSAs = new OSPFv3IntraAreaPrefixLSA[IntraAreaPrefixLSAs_arraysize];
        doParsimArrayUnpacking(b,this->IntraAreaPrefixLSAs,IntraAreaPrefixLSAs_arraysize);
    }
}

uint32_t OSPFv3LSUpdate::getLsaCount() const
{
    return this->lsaCount;
}

void OSPFv3LSUpdate::setLsaCount(uint32_t lsaCount)
{
    this->lsaCount = lsaCount;
}

void OSPFv3LSUpdate::setRouterLSAsArraySize(unsigned int size)
{
    OSPFv3RouterLSA *RouterLSAs2 = (size==0) ? nullptr : new OSPFv3RouterLSA[size];
    unsigned int sz = RouterLSAs_arraysize < size ? RouterLSAs_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        RouterLSAs2[i] = this->RouterLSAs[i];
    RouterLSAs_arraysize = size;
    delete [] this->RouterLSAs;
    this->RouterLSAs = RouterLSAs2;
}

unsigned int OSPFv3LSUpdate::getRouterLSAsArraySize() const
{
    return RouterLSAs_arraysize;
}

OSPFv3RouterLSA& OSPFv3LSUpdate::getRouterLSAs(unsigned int k)
{
    if (k>=RouterLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", RouterLSAs_arraysize, k);
    return this->RouterLSAs[k];
}

void OSPFv3LSUpdate::setRouterLSAs(unsigned int k, const OSPFv3RouterLSA& RouterLSAs)
{
    if (k>=RouterLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", RouterLSAs_arraysize, k);
    this->RouterLSAs[k] = RouterLSAs;
}

void OSPFv3LSUpdate::setNetworkLSAsArraySize(unsigned int size)
{
    OSPFv3NetworkLSA *NetworkLSAs2 = (size==0) ? nullptr : new OSPFv3NetworkLSA[size];
    unsigned int sz = NetworkLSAs_arraysize < size ? NetworkLSAs_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        NetworkLSAs2[i] = this->NetworkLSAs[i];
    NetworkLSAs_arraysize = size;
    delete [] this->NetworkLSAs;
    this->NetworkLSAs = NetworkLSAs2;
}

unsigned int OSPFv3LSUpdate::getNetworkLSAsArraySize() const
{
    return NetworkLSAs_arraysize;
}

OSPFv3NetworkLSA& OSPFv3LSUpdate::getNetworkLSAs(unsigned int k)
{
    if (k>=NetworkLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", NetworkLSAs_arraysize, k);
    return this->NetworkLSAs[k];
}

void OSPFv3LSUpdate::setNetworkLSAs(unsigned int k, const OSPFv3NetworkLSA& NetworkLSAs)
{
    if (k>=NetworkLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", NetworkLSAs_arraysize, k);
    this->NetworkLSAs[k] = NetworkLSAs;
}

void OSPFv3LSUpdate::setInterAreaPrefixLSAsArraySize(unsigned int size)
{
    OSPFv3InterAreaPrefixLSA *InterAreaPrefixLSAs2 = (size==0) ? nullptr : new OSPFv3InterAreaPrefixLSA[size];
    unsigned int sz = InterAreaPrefixLSAs_arraysize < size ? InterAreaPrefixLSAs_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        InterAreaPrefixLSAs2[i] = this->InterAreaPrefixLSAs[i];
    InterAreaPrefixLSAs_arraysize = size;
    delete [] this->InterAreaPrefixLSAs;
    this->InterAreaPrefixLSAs = InterAreaPrefixLSAs2;
}

unsigned int OSPFv3LSUpdate::getInterAreaPrefixLSAsArraySize() const
{
    return InterAreaPrefixLSAs_arraysize;
}

OSPFv3InterAreaPrefixLSA& OSPFv3LSUpdate::getInterAreaPrefixLSAs(unsigned int k)
{
    if (k>=InterAreaPrefixLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", InterAreaPrefixLSAs_arraysize, k);
    return this->InterAreaPrefixLSAs[k];
}

void OSPFv3LSUpdate::setInterAreaPrefixLSAs(unsigned int k, const OSPFv3InterAreaPrefixLSA& InterAreaPrefixLSAs)
{
    if (k>=InterAreaPrefixLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", InterAreaPrefixLSAs_arraysize, k);
    this->InterAreaPrefixLSAs[k] = InterAreaPrefixLSAs;
}

void OSPFv3LSUpdate::setLinkLSAsArraySize(unsigned int size)
{
    OSPFv3LinkLSA *LinkLSAs2 = (size==0) ? nullptr : new OSPFv3LinkLSA[size];
    unsigned int sz = LinkLSAs_arraysize < size ? LinkLSAs_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        LinkLSAs2[i] = this->LinkLSAs[i];
    LinkLSAs_arraysize = size;
    delete [] this->LinkLSAs;
    this->LinkLSAs = LinkLSAs2;
}

unsigned int OSPFv3LSUpdate::getLinkLSAsArraySize() const
{
    return LinkLSAs_arraysize;
}

OSPFv3LinkLSA& OSPFv3LSUpdate::getLinkLSAs(unsigned int k)
{
    if (k>=LinkLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", LinkLSAs_arraysize, k);
    return this->LinkLSAs[k];
}

void OSPFv3LSUpdate::setLinkLSAs(unsigned int k, const OSPFv3LinkLSA& LinkLSAs)
{
    if (k>=LinkLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", LinkLSAs_arraysize, k);
    this->LinkLSAs[k] = LinkLSAs;
}

void OSPFv3LSUpdate::setIntraAreaPrefixLSAsArraySize(unsigned int size)
{
    OSPFv3IntraAreaPrefixLSA *IntraAreaPrefixLSAs2 = (size==0) ? nullptr : new OSPFv3IntraAreaPrefixLSA[size];
    unsigned int sz = IntraAreaPrefixLSAs_arraysize < size ? IntraAreaPrefixLSAs_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        IntraAreaPrefixLSAs2[i] = this->IntraAreaPrefixLSAs[i];
    IntraAreaPrefixLSAs_arraysize = size;
    delete [] this->IntraAreaPrefixLSAs;
    this->IntraAreaPrefixLSAs = IntraAreaPrefixLSAs2;
}

unsigned int OSPFv3LSUpdate::getIntraAreaPrefixLSAsArraySize() const
{
    return IntraAreaPrefixLSAs_arraysize;
}

OSPFv3IntraAreaPrefixLSA& OSPFv3LSUpdate::getIntraAreaPrefixLSAs(unsigned int k)
{
    if (k>=IntraAreaPrefixLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", IntraAreaPrefixLSAs_arraysize, k);
    return this->IntraAreaPrefixLSAs[k];
}

void OSPFv3LSUpdate::setIntraAreaPrefixLSAs(unsigned int k, const OSPFv3IntraAreaPrefixLSA& IntraAreaPrefixLSAs)
{
    if (k>=IntraAreaPrefixLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", IntraAreaPrefixLSAs_arraysize, k);
    this->IntraAreaPrefixLSAs[k] = IntraAreaPrefixLSAs;
}

class OSPFv3LSUpdateDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3LSUpdateDescriptor();
    virtual ~OSPFv3LSUpdateDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3LSUpdateDescriptor);

OSPFv3LSUpdateDescriptor::OSPFv3LSUpdateDescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3LSUpdate", "inet::OSPFv3Packet")
{
    propertynames = nullptr;
}

OSPFv3LSUpdateDescriptor::~OSPFv3LSUpdateDescriptor()
{
    delete[] propertynames;
}

bool OSPFv3LSUpdateDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3LSUpdate *>(obj)!=nullptr;
}

const char **OSPFv3LSUpdateDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3LSUpdateDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3LSUpdateDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int OSPFv3LSUpdateDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3LSUpdateDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lsaCount",
        "RouterLSAs",
        "NetworkLSAs",
        "InterAreaPrefixLSAs",
        "LinkLSAs",
        "IntraAreaPrefixLSAs",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int OSPFv3LSUpdateDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsaCount")==0) return base+0;
    if (fieldName[0]=='R' && strcmp(fieldName, "RouterLSAs")==0) return base+1;
    if (fieldName[0]=='N' && strcmp(fieldName, "NetworkLSAs")==0) return base+2;
    if (fieldName[0]=='I' && strcmp(fieldName, "InterAreaPrefixLSAs")==0) return base+3;
    if (fieldName[0]=='L' && strcmp(fieldName, "LinkLSAs")==0) return base+4;
    if (fieldName[0]=='I' && strcmp(fieldName, "IntraAreaPrefixLSAs")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3LSUpdateDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",
        "OSPFv3RouterLSA",
        "OSPFv3NetworkLSA",
        "OSPFv3InterAreaPrefixLSA",
        "OSPFv3LinkLSA",
        "OSPFv3IntraAreaPrefixLSA",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3LSUpdateDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3LSUpdateDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3LSUpdateDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSUpdate *pp = (OSPFv3LSUpdate *)object; (void)pp;
    switch (field) {
        case 1: return pp->getRouterLSAsArraySize();
        case 2: return pp->getNetworkLSAsArraySize();
        case 3: return pp->getInterAreaPrefixLSAsArraySize();
        case 4: return pp->getLinkLSAsArraySize();
        case 5: return pp->getIntraAreaPrefixLSAsArraySize();
        default: return 0;
    }
}

std::string OSPFv3LSUpdateDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSUpdate *pp = (OSPFv3LSUpdate *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getLsaCount());
        case 1: {std::stringstream out; out << pp->getRouterLSAs(i); return out.str();}
        case 2: {std::stringstream out; out << pp->getNetworkLSAs(i); return out.str();}
        case 3: {std::stringstream out; out << pp->getInterAreaPrefixLSAs(i); return out.str();}
        case 4: {std::stringstream out; out << pp->getLinkLSAs(i); return out.str();}
        case 5: {std::stringstream out; out << pp->getIntraAreaPrefixLSAs(i); return out.str();}
        default: return "";
    }
}

bool OSPFv3LSUpdateDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSUpdate *pp = (OSPFv3LSUpdate *)object; (void)pp;
    switch (field) {
        case 0: pp->setLsaCount(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFv3LSUpdateDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(OSPFv3RouterLSA));
        case 2: return omnetpp::opp_typename(typeid(OSPFv3NetworkLSA));
        case 3: return omnetpp::opp_typename(typeid(OSPFv3InterAreaPrefixLSA));
        case 4: return omnetpp::opp_typename(typeid(OSPFv3LinkLSA));
        case 5: return omnetpp::opp_typename(typeid(OSPFv3IntraAreaPrefixLSA));
        default: return nullptr;
    };
}

void *OSPFv3LSUpdateDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSUpdate *pp = (OSPFv3LSUpdate *)object; (void)pp;
    switch (field) {
        case 1: return (void *)static_cast<omnetpp::cObject *>(&pp->getRouterLSAs(i)); break;
        case 2: return (void *)static_cast<omnetpp::cObject *>(&pp->getNetworkLSAs(i)); break;
        case 3: return (void *)static_cast<omnetpp::cObject *>(&pp->getInterAreaPrefixLSAs(i)); break;
        case 4: return (void *)static_cast<omnetpp::cObject *>(&pp->getLinkLSAs(i)); break;
        case 5: return (void *)static_cast<omnetpp::cObject *>(&pp->getIntraAreaPrefixLSAs(i)); break;
        default: return nullptr;
    }
}

Register_Class(OSPFv3LSAck);

OSPFv3LSAck::OSPFv3LSAck(const char *name, int kind) : ::inet::OSPFv3Packet(name,kind)
{
    this->lsas = 0;
    lsaHeaders_arraysize = 0;
    this->lsaHeaders = 0;
}

OSPFv3LSAck::OSPFv3LSAck(const OSPFv3LSAck& other) : ::inet::OSPFv3Packet(other)
{
    lsaHeaders_arraysize = 0;
    this->lsaHeaders = 0;
    copy(other);
}

OSPFv3LSAck::~OSPFv3LSAck()
{
    delete [] this->lsaHeaders;
}

OSPFv3LSAck& OSPFv3LSAck::operator=(const OSPFv3LSAck& other)
{
    if (this==&other) return *this;
    ::inet::OSPFv3Packet::operator=(other);
    copy(other);
    return *this;
}

void OSPFv3LSAck::copy(const OSPFv3LSAck& other)
{
    this->lsas = other.lsas;
    delete [] this->lsaHeaders;
    this->lsaHeaders = (other.lsaHeaders_arraysize==0) ? nullptr : new OSPFv3LSAHeader[other.lsaHeaders_arraysize];
    lsaHeaders_arraysize = other.lsaHeaders_arraysize;
    for (unsigned int i=0; i<lsaHeaders_arraysize; i++)
        this->lsaHeaders[i] = other.lsaHeaders[i];
}

void OSPFv3LSAck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::OSPFv3Packet::parsimPack(b);
    doParsimPacking(b,this->lsas);
    b->pack(lsaHeaders_arraysize);
    doParsimArrayPacking(b,this->lsaHeaders,lsaHeaders_arraysize);
}

void OSPFv3LSAck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::OSPFv3Packet::parsimUnpack(b);
    doParsimUnpacking(b,this->lsas);
    delete [] this->lsaHeaders;
    b->unpack(lsaHeaders_arraysize);
    if (lsaHeaders_arraysize==0) {
        this->lsaHeaders = 0;
    } else {
        this->lsaHeaders = new OSPFv3LSAHeader[lsaHeaders_arraysize];
        doParsimArrayUnpacking(b,this->lsaHeaders,lsaHeaders_arraysize);
    }
}

uint32_t OSPFv3LSAck::getLsas() const
{
    return this->lsas;
}

void OSPFv3LSAck::setLsas(uint32_t lsas)
{
    this->lsas = lsas;
}

void OSPFv3LSAck::setLsaHeadersArraySize(unsigned int size)
{
    OSPFv3LSAHeader *lsaHeaders2 = (size==0) ? nullptr : new OSPFv3LSAHeader[size];
    unsigned int sz = lsaHeaders_arraysize < size ? lsaHeaders_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        lsaHeaders2[i] = this->lsaHeaders[i];
    lsaHeaders_arraysize = size;
    delete [] this->lsaHeaders;
    this->lsaHeaders = lsaHeaders2;
}

unsigned int OSPFv3LSAck::getLsaHeadersArraySize() const
{
    return lsaHeaders_arraysize;
}

OSPFv3LSAHeader& OSPFv3LSAck::getLsaHeaders(unsigned int k)
{
    if (k>=lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", lsaHeaders_arraysize, k);
    return this->lsaHeaders[k];
}

void OSPFv3LSAck::setLsaHeaders(unsigned int k, const OSPFv3LSAHeader& lsaHeaders)
{
    if (k>=lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", lsaHeaders_arraysize, k);
    this->lsaHeaders[k] = lsaHeaders;
}

class OSPFv3LSAckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFv3LSAckDescriptor();
    virtual ~OSPFv3LSAckDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OSPFv3LSAckDescriptor);

OSPFv3LSAckDescriptor::OSPFv3LSAckDescriptor() : omnetpp::cClassDescriptor("inet::OSPFv3LSAck", "inet::OSPFv3Packet")
{
    propertynames = nullptr;
}

OSPFv3LSAckDescriptor::~OSPFv3LSAckDescriptor()
{
    delete[] propertynames;
}

bool OSPFv3LSAckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFv3LSAck *>(obj)!=nullptr;
}

const char **OSPFv3LSAckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFv3LSAckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFv3LSAckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int OSPFv3LSAckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *OSPFv3LSAckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lsas",
        "lsaHeaders",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int OSPFv3LSAckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsas")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsaHeaders")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFv3LSAckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",
        "OSPFv3LSAHeader",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFv3LSAckDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OSPFv3LSAckDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OSPFv3LSAckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSAck *pp = (OSPFv3LSAck *)object; (void)pp;
    switch (field) {
        case 1: return pp->getLsaHeadersArraySize();
        default: return 0;
    }
}

std::string OSPFv3LSAckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSAck *pp = (OSPFv3LSAck *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getLsas());
        case 1: {std::stringstream out; out << pp->getLsaHeaders(i); return out.str();}
        default: return "";
    }
}

bool OSPFv3LSAckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSAck *pp = (OSPFv3LSAck *)object; (void)pp;
    switch (field) {
        case 0: pp->setLsas(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFv3LSAckDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(OSPFv3LSAHeader));
        default: return nullptr;
    };
}

void *OSPFv3LSAckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFv3LSAck *pp = (OSPFv3LSAck *)object; (void)pp;
    switch (field) {
        case 1: return (void *)static_cast<omnetpp::cObject *>(&pp->getLsaHeaders(i)); break;
        default: return nullptr;
    }
}

} // namespace inet

