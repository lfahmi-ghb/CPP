#pragma once
#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstring>
#include<vector>
#include<sstream>
#include <string>
#include <utility>
#include <stack>
#include<algorithm>
#include <numeric>
#include <functional>
#include <list>



using namespace std;

namespace sdds
{


    struct Song {
        string artist;
        string title;
        string album;
        string price;
        string year;
        string mins;
        string secs;
        int length;
        double m_price;
    };

    class SongCollection {
        int total;
        vector<Song> songs;

    public:
        SongCollection(const char*);

        void display(ostream& out) const;

        void sort(string);

        void cleanAlbum();

        bool inCollection(const char*) const;

        list<Song> getSongsForArtist(string) const;
    };

    ostream& operator<<(ostream& out, const Song& theSong);
}

#endif