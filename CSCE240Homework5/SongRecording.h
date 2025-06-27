// Copyright 2025 Simion Cartis
#ifndef _SONGRECORDING_H_
#define _SONGRECORDING_H_


#include<string>
using std::string;

namespace csce240_programming_assignment_5 {

class SongRecording {
 public:
  explicit SongRecording(string title = "untitled", string primary_artist =
                         "unknown", int track_length = 0,
                         int num_of_artists = 1);

  SongRecording(const SongRecording& to_copy);

  ~SongRecording() {delete [] artist_names_;}

  SongRecording& operator = (const SongRecording& to_copy);

  string GetTitle() const {return title_;}
  int GetNumArtists() const {return num_of_artists_;}
  string GetArtist(int artist = 1) const;
  int GetTrackLength() const {return track_length_;}

  void SetTitle(string title);
  void SetNumArtists(int num_of_artists);
  void SetArtist(string artist, int position = 1);
  void SetTrackLength(int length);

 private:
  string title_;
  int track_length_;
  int num_of_artists_;
  string * artist_names_;
};
}  // end namespace csce240_programming_assignment_5
#endif
