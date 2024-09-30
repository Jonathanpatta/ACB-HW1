#include <bits/stdc++.h>
using namespace std;

void output_to_file(string input,string filename){
    std::ofstream out(filename);
    out << input;
    out.close();
}

std::string read_string_from_file(const std::string &file_path) {

    const std::ifstream input_stream(file_path);
    if (input_stream.fail()) {
        throw std::runtime_error("Failed to open file");
    }
    string s;
    if(input_stream){
        std::ostringstream buffer;
        buffer << input_stream.rdbuf();
        s = buffer.str();
    }
    return s;
}

vector<string> split(string s,char c){

    std::stringstream test(s);
    std::string segment;
    std::vector<std::string> seglist;
    while(std::getline(test, segment, c))
    {
       seglist.push_back(segment);
    }
    return seglist;
}

vector<int> bruteforce(string s){

    vector<string> sp = split(s,'\n');
    string st = sp[0];
    string word = sp[1];
    vector<int> ans;
    int wi = 0;
    for(int i=0;i<st.size()+1-word.size();i++){
        bool flag=true;
        for(int j=0;j<word.size();j++){
            if(word[j]!=st[i+j]){
                flag = false;
                break;
            }
        }
        if(flag){
            ans.push_back(i+1);
        }
    }
    return ans;
}


vector<int> getZarr(string str,int &matches,int &mismatches)
{
    int n = str.size();
    vector<int> Z(n);
    int leftptr = 0;
    int rightptr = 0;
    int k;

    for (int i = 1; i < n; i++)
    {
        if (i > rightptr)
        {
            leftptr = rightptr = i;
            while (rightptr<n && str[rightptr-leftptr] == str[rightptr]){
                rightptr++;
            }
            matches += rightptr-leftptr;
            if(rightptr<n)
                mismatches++;
                
            Z[i] = rightptr-leftptr;
            rightptr--;
        }
        else
        {
            k = i-leftptr;
            if (Z[k] < rightptr-i+1)
                Z[i] = Z[k];
            else
            {
                leftptr = i;
                int prevrptr = rightptr;
                while (rightptr<n && str[rightptr-leftptr] == str[rightptr]){
                    rightptr++;
                }
                matches += rightptr-prevrptr-1;
                if(rightptr<n)
                    mismatches++;
                    
                Z[i] = rightptr-leftptr;
                rightptr--;
            }
        }
    }
    return Z;
}

vector<int> zalgo(string s,int &matches,int &mismatches)
{
    // Create concatenated string "P$T"
    vector<string> sp = split(s,'\n');
    string st = sp[0];
    string word = sp[1];

    // Construct Z array

    string newst = word + '$' +st;
    
    vector<int> Z = getZarr(newst,matches,mismatches);



    vector<int> inds;
    for (int i = 0; i < Z.size(); ++i)
    {
        if (Z[i] == word.size()){
            inds.push_back(i-word.size());
        }
    }
    return inds;
}


void hw1q1(string filename){

    string s = read_string_from_file(filename);
    int matches = 0;
    int mismatches =0;
    auto inds = zalgo(s,matches,mismatches);
    // auto inds = bruteforce(s);
    string output = "";
    for(int i:inds){
        output+=to_string(i)+'\n';
    }
    output += "Number of comparisons: " + to_string(matches+mismatches) + "\n";
    output += "Number of matches: " + to_string(matches) + "\n";
    output += "Number of mismatches: " + to_string(mismatches) + "\n";
    auto fn = split(filename,'_');
    int fnum = atoi(fn[1].c_str());
    cout<<output;
    output_to_file(output,"sol_"+to_string(fnum));

}

#include <filesystem>
namespace fs = std::filesystem;

int main(int argc, char** argv) {
    
    if(argc==2 ){
        string cmd = argv[1];

        if(cmd != "all"){
            string file = string(argv[1]);
            hw1q1(file);
        }
        else{
            for (const auto & entry : fs::directory_iterator(".")) {
                if (entry.is_regular_file() && entry.path().string().find("_") != std::string::npos && entry.path().string().find("sol_") == std::string::npos) {
                    std::cout << entry.path() << std::endl;
                    hw1q1(entry.path().string());
                }
            }
        }
    }    
    return 0;
}