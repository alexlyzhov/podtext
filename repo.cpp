#include "repo.h"

using namespace std;

Repo::Repo() : langs({"ch", "ja"}){

}

Repo::~Repo() {

}

vector<string> Repo::getLangs() {
    return langs;
}

vector<Source> Repo::getSources(string lang) {
    vector<Source> sources;
    Source source("http://www.slow-chinese.com/podcasts/Slow_Chinese_150.mp3",
                  "http://www.slow-chinese.com/podcast/150-e-gao-de-chi-du/");
    sources.push_back(source);
    return sources;
}
