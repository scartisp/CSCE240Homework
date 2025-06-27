// Copyright Simion Cartis

#include"StreamingTrack.h"
#include"SongRecording.h"
#include<string>
using std::string;

namespace csce240_programming_assignment_5 {

StreamingTrack::StreamingTrack(string title, string primary_artist,
                              int track_length, int num_of_aritsts,
                              string primary_genre, int num_of_streams) :
                              SongRecording(title, primary_artist,
                                track_length, num_of_aritsts),
                              num_of_genres_(0), genres_(nullptr),
                              num_of_streams_(0) {
  AddGenre(primary_genre);
  SetStreams(num_of_streams);
}

StreamingTrack::StreamingTrack(const StreamingTrack& to_copy) :
                              SongRecording(to_copy),
                              num_of_genres_(to_copy.num_of_genres_),
                              genres_(nullptr),
                              num_of_streams_(to_copy.num_of_streams_) {
  if (num_of_genres_ > 0) {
    genres_ = new string[num_of_genres_];
    for (int i = 0; i < num_of_genres_; ++i) {
      genres_[i] = to_copy.genres_[i];
    }
  }
}

StreamingTrack::StreamingTrack(const SongRecording& to_copy,
                               string primary_genre, int num_of_streams) :
                               SongRecording(to_copy), num_of_genres_(0),
                               genres_(nullptr), num_of_streams_(0) {
  AddGenre(primary_genre);
  SetStreams(num_of_streams);
  }

StreamingTrack& StreamingTrack::operator =(const StreamingTrack& to_copy) {
  SongRecording::operator =(to_copy);
  num_of_genres_ = to_copy.num_of_genres_;
  num_of_streams_ = to_copy.num_of_streams_;
  if (genres_ != nullptr) {
    delete [] genres_;
  }
  if (num_of_genres_ == 0) {
    genres_ = nullptr;
  } else {
    genres_ = new string[num_of_genres_];
    for (int i = 0; i < num_of_genres_; ++i) {
      genres_[i] = to_copy.genres_[i];
    }
  }
  return *this;
}

void StreamingTrack::AddGenre(string genre) {
  if (num_of_genres_ != 0) {
    if (IsGenre(genre)) {
      return;
    }
    string * temp = genres_;
    genres_ = new string[num_of_genres_ +1];
    for (int i = 0; i < num_of_genres_; ++i) {
      genres_[i] = temp[i];
    }
    genres_[num_of_genres_] = genre;
    ++num_of_genres_;
    delete [] temp;
    return;
  } else {
  genres_ = new string[1];
  genres_[0] = genre;
  ++num_of_genres_;
  }
}

void StreamingTrack::RemoveGenre(string genre) {
  if (num_of_genres_ == 0 || (num_of_genres_ == 1 && genres_[0] != genre)) {
    return;
  }
  if (num_of_genres_ == 1 && genres_[0] == genre) {
    delete [] genres_;
    genres_ = nullptr;
    --num_of_genres_;
  } else if (IsGenre(genre)) {
    string * temp = genres_;
    genres_ = new string[num_of_genres_ -1];
    int i = 0;
    int j = 0;
    while (i < num_of_genres_) {
      if (temp[i] != genre) {
        genres_[j] = temp[i];
        ++j;
      }
      ++i;
    }
    --num_of_genres_;
    delete[] temp;
  }
}

bool StreamingTrack::IsGenre(string genre) const {
  if (num_of_genres_ != 0) {
    for (int i = 0; i < num_of_genres_; ++i) {
      if (genres_[i] == genre) {
        return true;
      }
    }
  }
  return false;
}

string StreamingTrack::GetGenre(int genre) const {
  if (genre >=1 || genre <= num_of_genres_) {
    return genres_[genre-1];
  }
  return "out of bounds";
}

void StreamingTrack::SetStreams(int streams) {
  if (streams >= 0) {
    num_of_streams_ = streams;
  }
}

void StreamingTrack::AddStreams(int to_add) {
  if (to_add > 0) {
    num_of_streams_ += to_add;
  }
}
}  // end namespace csce240_programming_assignment_5
