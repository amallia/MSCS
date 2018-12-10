#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT project_indexView : public TActionView
{
  Q_OBJECT
public:
  project_indexView() : TActionView() { }
  QString toString();
};

QString project_indexView::toString()
{
  responsebody.reserve(917);
  responsebody += QLatin1String("<!DOCTYPE html>\n<html>\n<head>   \n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n\n<h1>(En/De)crypt Selection Menu</h1>\n\n\n<br />\n \n");
  responsebody += QVariant(formTag(urla("des"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p> \n    <input type=\"submit\" value=\"des\" />\n  </p>\n</form>\n");
  responsebody += QVariant(formTag(urla("tripleDES"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <input type=\"submit\" value=\"tripleDES\" />\n  </p>\n</form>\n");
  responsebody += QVariant(formTag(urla("elgamal"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <input type=\"submit\" value=\"elgamal\" />\n  </p>\n</form>\n</div>\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(project_indexView)

#include "project_indexView.moc"
