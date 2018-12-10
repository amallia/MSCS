#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT project_desView : public TActionView
{
  Q_OBJECT
public:
  project_desView() : TActionView() { }
  QString toString();
};

QString project_desView::toString()
{
  responsebody.reserve(816);
  responsebody += QLatin1String("<!DOCTYPE html>\n<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n\n<h1>DES (En/De)crypt Selection Menu</h1>\n\n\n<br />\n<div>\n  <input type=\"radio\" id=\"ECB\" name=\"ciphermode\" value=\"ecb\"\n         checked>\n  <label for=\"des\">DES</label>\n</div>\n\n<div>\n  <input type=\"radio\" id=\"3des\" name=\"ciphermode\" value=\"3des\">\n  <label for=\"3des\">Triple DES</label>\n</div>\n\n");
  responsebody += QVariant(formTag(urla("elgamal"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <input type=\"submit\" value=\"elgamal\" />\n  </p>\n</form>\n</div>\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(project_desView)

#include "project_desView.moc"
