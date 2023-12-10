#include "PathManager.h"

 void PathManager::setPath(const QString &path){
  if (m_path == path) return;
  m_path = path;
  emit pathChanged();
 }

 void PathManager::changePath(int ind, double x, double y) {
	 // "M 0 384 C 144 96, 336 96, 480 384"
     //  0 1  2  3  4   5   6   7   8   9
   std::string s;
   std::stringstream ss(m_path.toStdString().c_str());
   std::vector<std::string> v;
   while (std::getline(ss, s, ' ')) {
     v.push_back(s);
   }
   std::string _x = std::to_string((int)x);
   std::string _y = std::to_string((int)y);
   if (ind == 1) {
     v[1] = _x;
     v[2] = _y;
   } else if (ind == 4) {
     v[2 * ind] = _x;
     v[2 * ind + 1] = _y;
   }else{
     v[2 * ind] = _x;
     v[2 * ind + 1] = _y + ",";
   }

   std::string concatenatedString;
   for (size_t i = 0; i < v.size(); ++i) {
     concatenatedString += v[i];
     if (i != v.size() - 1) {
       concatenatedString +=
           " ";
     }
   }

   QString qstr = QString::fromStdString(concatenatedString); 
   setPath(qstr);
   //emit pathChanged();
 }
