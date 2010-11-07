#include <map>

int main(int argc, char** argc){
  map <int, vector<int> > mymap;
  mymap m;

  for( mymap::iterator i = m.begin(); i != m.end(); ++i ) {
    vector<int> v = (*i).second;
    string Key = (*iter).first;
    cout << Key;
    for (unsigned i = 0; i < tempVec.size(); i++) {
      cout << " " << tempVec[i];
    }
    cout << endl;
  }
}
