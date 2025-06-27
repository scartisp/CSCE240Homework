// Copyright 2025 Simion Cartis

#ifndef _STREAMINGTRACK_H_
#define _STREAMINGTRACK_H_

#include<string>
using std::string;
#include"SongRecording.h"

namespace csce240_programming_assignment_5 {

class StreamingTrack : public SongRecording {
 public:
  explicit StreamingTrack(string title = "untitled",
                          string primary_artist = "unknown",
                          int track_length = 0, int num_of_aritsts = 1,
                          string primary_genre = "pop", int num_of_streams = 0);

  StreamingTrack(const StreamingTrack& to_copy);

  StreamingTrack(const SongRecording& to_copy, string primary_genre = "pop",
                 int num_of_streams = 0);

  ~StreamingTrack() {delete [] genres_;}

  StreamingTrack& operator = (const StreamingTrack& to_copy);

  int GetStreams() const {return num_of_streams_;}
  int GetNumGenres() const {return num_of_genres_;}
  string GetGenre(int genre = 1) const;

  void SetStreams(int num_of_streams);
  void AddStreams(int to_add);

  bool IsGenre(string genre) const;
  void AddGenre(string genre);
  void RemoveGenre(string genre);

 private:
  int num_of_genres_;
  string * genres_;
  int num_of_streams_;
};

}  // end namespace csce240_programming_assignment_5
#endif
