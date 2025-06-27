// Copyright 2025 Simion Cartis
#include"SongRecording.h"


#include<string>
using std::string;


namespace csce240_programming_assignment_5 {
SongRecording::SongRecording(string title, string primary_artist,
                            int track_length, int num_of_artists) :
                            title_("untitled"), track_length_(0),
                            num_of_artists_(1),
                            artist_names_(new string[1]{"unknown"}) {
  SetTitle(title);
  SetTrackLength(track_length);
  SetNumArtists(num_of_artists);
  SetArtist(primary_artist, 1);
}


SongRecording::SongRecording(const SongRecording& to_copy) :
                            title_(to_copy.title_),
                            track_length_(to_copy.track_length_),
                            num_of_artists_(1),
                            artist_names_(new string[1]{"unknown"}) {
  SetNumArtists(to_copy.num_of_artists_);
  if (to_copy.artist_names_ != nullptr) {
    for (int i = 0; i < to_copy.num_of_artists_; ++i) {
      artist_names_[i] = to_copy.artist_names_[i];
    }
  }
}


SongRecording& SongRecording::operator =(const SongRecording& to_copy) {
  title_ = to_copy.title_;
  track_length_ = to_copy.track_length_;
  SetNumArtists(to_copy.num_of_artists_);
  if (to_copy.artist_names_ != nullptr) {
    for (int i = 0; i < to_copy.num_of_artists_; ++i) {
      artist_names_[i] = to_copy.artist_names_[i];
    }
  }
  return *this;
}




void SongRecording::SetTitle(string title) {
  if (title.size() >= 1) {
    title_ = title;
  }
}


void SongRecording::SetNumArtists(int num_of_artists) {
  if (num_of_artists <= 0) {
    return;
  }
  if (num_of_artists != num_of_artists_) {
    num_of_artists_ = num_of_artists;
    if (artist_names_ != nullptr) {
      delete [] artist_names_;
    }
    artist_names_ = new string[num_of_artists];
  }
    for (int i = 0; i < num_of_artists; ++i) {
      artist_names_[i] = "unkown";
  }
}


void SongRecording::SetArtist(string artist, int position) {
  if (artist.size() >= 1 && position >= 1 && position <= num_of_artists_) {
    artist_names_[position-1] = artist;
  }
}


void SongRecording::SetTrackLength(int track_length) {
  if (track_length >= 0) {
    track_length_ = track_length;
  }
}

string SongRecording::GetArtist(int artist) const {
  if (artist >= 1 && artist <= num_of_artists_) {
    return artist_names_[artist-1];
  }
  return "out of bounds";
}


}  // end namespace csce240_programming_assignment_5
