#include "DES.h"

#include <TreeFrogModel>
#include "DESobject.h"

DES::DES()
    : TAbstractModel(), d(new DESObject())
{

}

DES::~DES()
{
    // If the reference count becomes 0,
    // the shared data object 'DESObject' is deleted.
}

int DES::key() const
{
    return d->get_key();
}

QString DES::plaintext() const
{
    return d->decrypt(ciphertext);
}

QString DES::ciphertext() const
{
    return d->encrypt(plaintext);
}

QString DES::body() const
{
    return d->body;
}

void DES::setBody(const QString &body)
{
    d->body = body;
}

QDateTime DES::createdAt() const
{
    return d->created_at;
}

QDateTime DES::updatedAt() const
{
    return d->updated_at;
}

int DES::lockRevision() const
{
    return d->lock_revision;
}

DES &DES::operator=(const DES &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

DES DES::create(const QString &title, const QString &body)
{
    DESObject obj;
    obj.title = title;
    obj.body = body;
    if (!obj.create()) {
        return DES();
    }
    return DES(obj);
}

DES DES::create(const QVariantMap &values)
{
    DES model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

DES DES::get(int id)
{
    TSqlORMapper<DESObject> mapper;
    return DES(mapper.findByPrimaryKey(id));
}

DES DES::get(int id, int lockRevision)
{
    TSqlORMapper<DESObject> mapper;
    TCriteria cri;
    cri.add(DESObject::Id, id);
    cri.add(DESObject::LockRevision, lockRevision);
    return DES(mapper.findFirst(cri));
}

int DES::count()
{
    TSqlORMapper<DESObject> mapper;
    return mapper.findCount();
}

QList<DES> DES::getAll()
{
    return tfGetModelListByCriteria<DES, DESObject>(TCriteria());
}

QJsonArray DES::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<DESObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<DESObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(DES(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *DES::modelData()
{
    return d.data();
}

const TModelObject *DES::modelData() const
{
    return d.data();
}


// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(DES)
