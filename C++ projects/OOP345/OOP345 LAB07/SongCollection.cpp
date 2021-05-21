//Name: Lara Fahmi
//Student Number: 109742197

#define _CRT_SECURE_NO_WARNINGS

#include "SongCollection.h"

namespace sdds
{



    //REMOVE THE SPACES
    string& removeSpaces(string& whole) {
        whole.erase(whole.find_last_not_of(' ') + 1);
        whole.erase(0, whole.find_first_not_of(' '));
        return whole;
    }


    SongCollection::SongCollection(const char* filename) {
        total = 0;
        std::ifstream file(filename);
        if (!file) {
            throw "no file";
        }
        while (file){
            Song song;
            string str, temp_length, temp_price;
          
            getline(file, str, '\n');
            //get title from pos 0 => remove spaces => erase title => extract next from pos 0 
            //TITLE, ARTIST and ALBUM have exactly 25 characters; 
            //YEAR, LENGTH and PRICE have exactly 5 characters.

            //removeSpaces(str);

                    song.title = str.substr(0, 25);         
                    removeSpaces(song.title);
                    str.erase(0, 25);

                    song.artist = str.substr(0, 25);
                    removeSpaces(song.artist);
                    str.erase(0, 25);
         

                    song.album = str.substr(0, 25);
                    removeSpaces(song.album);
                    str.erase(0, 25);
           


                    song.year = str.substr(0, 5);
                    removeSpaces(song.year);
                    str.erase(0, 5);
          


                    temp_length = str.substr(0, 5);
                    str.erase(0, 5);
                    removeSpaces(temp_length);
                    stringstream ssl (temp_length);
                    ssl >> song.length;


                   song.mins = to_string(song.length / 60);


                   song.secs = to_string(song.length % 60);

                   temp_price = str.substr(0, 5);
                   removeSpaces(temp_price);
                   song.price = temp_price;
                        stringstream ssp(temp_price);
                        ssp >> song.m_price;


             songs.push_back(song);
        }
        //removes the last element
        songs.pop_back();
    }

    void SongCollection::display(ostream& out) const {

    //    for_each(songs.begin(), songs.end(), [&](const Song& song) {out << song << endl; });
        auto s = [&](Song song) { out << song<< std::endl; };
        std::for_each(songs.begin(), songs.end(), s);

       
        int totalTime = 0, hour, mins;
   
        auto time = [&](Song songs) { totalTime += songs.length; };
        std::for_each(songs.begin(), songs.end(), time);

        int scsPerHour = 3600;
        hour = totalTime / scsPerHour;
        mins = (totalTime - (hour) * scsPerHour) / 60;

        //  DISPLAY THIS
        out << std::setw(89) << std::setfill('-') << '\n';
        out << std::setfill(' ') << "|";
        out << std::right << std::setw(78) << std::setfill(' ');
        out << "Total Listening Time: " << hour<< ":" 
                                        << mins << ":" 
                                        << totalTime - (hour) *scsPerHour - ((totalTime - (totalTime / scsPerHour) * scsPerHour) / 60) * 60 << " |" << std::endl;
    }

    void SongCollection::sort(string song)
    {
        if (song == "title") {
            std::sort(songs.begin(), songs.end(), [](Song x, Song z) {
                return x.title < z.title;
                });
        }
        else if (song == "album") {
            std::sort(songs.begin(), songs.end(), [](Song x, Song z) {
                return x.album < z.album;
                });
        }
        else if (song == "length") {
            std::sort(songs.begin(), songs.end(), [](Song x, Song z) {
                return x.length < z.length;
                });
        }
    }

    void SongCollection::cleanAlbum() {
        for (auto& i : songs) {
            if (i.album == "[None]") {
                //i.album = nullptr;
                i.album = "";
            }
        }
    }

    bool SongCollection::inCollection(const char* str) const {
          auto found = [=](Song songs) {
              return  str == songs.artist; 
          };
    //return true if any within range of found
          return std::any_of(songs.begin(), songs.end(), found);
    }

    list<Song> SongCollection::getSongsForArtist(string song) const {
        list<Song> theSongs;
        for (auto& i : songs){
            if (i.artist == song) {
                theSongs.push_back(i);
            }
        }
        return theSongs;
    }

    ostream& operator<<(ostream& out, const Song& theSong) {
  
        out <<  "| " << left << setw(20) << theSong.title;
        out << " | " << left << setw(15) << theSong.artist;
        out << " | " << left << setw(20) << theSong.album;
        out << " | " << right << setw(6) << theSong.year;
        out << " | " << theSong.mins << ":" << setw(2) << setfill('0') << theSong.secs << setfill(' ');
        out << " | " << theSong.m_price << " |";

        return out;
    }
}