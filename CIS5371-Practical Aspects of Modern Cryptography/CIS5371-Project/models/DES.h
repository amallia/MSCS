#ifndef DES_H
#define DES_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class DESObject;
class QJsonArray;


class T_MODEL_EXPORT DES : public TAbstractModel
{
public:
    DES();
    ~DES();

    int key() const;
    QString plaintext() const;
    QString ciphertext() const;

    bool process() override { return TAbstractModel::process(); }

    static DES create(const QString &key, const QString &plaintext, const QString &ciphertext);


private:

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
};

Q_DECLARE_METATYPE(DES)
Q_DECLARE_METATYPE(QList<DES>)

#endif // DES_H
