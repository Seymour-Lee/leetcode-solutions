class FileSystem {
public:
	FileSystem() {
	    dTable["/"];
	}

	vector<string> ls(string path) {
		vector<string> ans;
		if (fTable.find(path) != fTable.end()){
			int i = path.size() - 1;
			while (i >= 0 && path[i] != '/') --i;
			ans.push_back(path.substr(i + 1));
			return ans;
		}
		if (dTable.find(path) != dTable.end()){
			for (auto s : dTable[path]) ans.push_back(s);
		}
		return ans;
	}

	void mkdir(string path){
		string prev = "/";
		int prevPos = 1;
		for (int i = 1; i <= path.size(); ++i){
			if (path[i] == '/' || path[i] == 0){
				dTable[prev].insert(path.substr(prevPos, i - prevPos));
				prevPos = i+1;
				prev = path.substr(0, i);
			}
		}
	}

	void addContentToFile(string filePath, string content){
		int i = filePath.size() - 1;
		while (i >= 0 && filePath[i] != '/') --i;
		string path = filePath.substr(0, i);
		string file = filePath.substr(i + 1);
		if (path.empty()) path = "/";
		if (dTable.find(path) == dTable.end()) mkdir(path);
		dTable[path].insert(file);
		fTable[filePath].append(content);
	}

	string readContentFromFile(string filePath){
		if (fTable.find(filePath) != fTable.end()) return fTable[filePath];
		return "";
	}
    
private:
	unordered_map<string, set<string>> dTable;  // dir name to contents
	unordered_map<string, string> fTable; //file name to contents 
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */