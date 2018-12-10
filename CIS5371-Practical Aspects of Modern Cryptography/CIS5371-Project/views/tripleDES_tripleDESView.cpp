#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT tripleDES_tripleDESView : public TActionView
{
  Q_OBJECT
public:
  tripleDES_tripleDESView() : TActionView() { }
  QString toString();
};

QString tripleDES_tripleDESView::toString()
{
  responsebody.reserve(1296);
  responsebody += QLatin1String("<!DOCTYPE html>\n<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n\n<h1>(En/De)crypt Selection Menu</h1>\n\n\n<br />\n<div>\n  <input type=\"radio\" id=\"des\" name=\"cipher\" value=\"des\"\n         checked>\n  <label for=\"des\">DES</label>\n</div>\n\n<div>\n  <input type=\"radio\" id=\"3des\" name=\"cipher\" value=\"3des\">\n  <label for=\"3des\">Triple DES</label>\n</div>\n\n<div>\n  <input type=\"radio\" id=\"elgamal\" name=\"cipher\" value=\"elgamal\">\n  <label for=\"elgamal\">ElGamal</label>\n</div>\n");
  responsebody += QVariant(formTag(urla("des"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <input type=\"submit\" value=\"des\" />\n  </p>\n</form>\n");
  responsebody += QVariant(formTag(urla("3des"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <input type=\"submit\" value=\"3des\" />\n  </p>\n</form>\n");
  responsebody += QVariant(formTag(urla("elgamal"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <input type=\"submit\" value=\"elgamal\" />\n  </p>\n</form>\n</div>\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(tripleDES_tripleDESView)

#include "tripleDES_tripleDESView.moc"
