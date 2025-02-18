#ifndef FILTER_GENRE_BUTTON_H
#define FILTER_GENRE_BUTTON_H

#include "Button.h"
#include "FilterableWidget.h"

// Represents a FilterGenreButton, which in our program has a text ("Action","Drama"), and when pressed filters movies by that genre.
// When filtering, we also take as consideration all the other widgets that may have filtered the movies.
class FilterGenreButton final : public  Button, public FilterableWidget
{
private:

	// Updates the state of the filter genre buttons
	void update() override;

	// Draws all the filter genre buttons
	void draw() override;

	//Performs the filtering action when the button is pressed
	//\param movie_list: a vector of all the movies
	void takeAction(const std::vector<Movie*>& movie_list) override;

	// Filters all movies by genre
	// \param movie_list: a vector of all the movies
	void filterByGenre(const std::vector<Movie*>& movie_list);

	// Creates A map in which the key is a genre text ("Action","Drama"...) and the value is an unordered set of all the movies that have that specific genre.
	// Its used map quickly filter movies by genre. 
	void createGenreMap(const std::vector<Movie*>& movie_list);

	// Resets the state of the button by clearing all the necessary variables (called when reset filter button is pressed).
	void clear() override;

private:

	using genreMap = std::unordered_map<std::string, std::unordered_set<Movie*>>;

private:

	// A map in which the key is a genre text ("Action","Drama"...) and the value is an unordered set of all the movies that have that specific genre.
	//Its used map quickly filter movies by genre. 
	static inline genreMap s_genreMap{};

	// A set of genre buttons that have been pressed, stored by their names. It is static because every
	//filter genre button needs to know about it when filtering.
	static inline std::unordered_set<std::string> s_scanned_genres;

	//Bool indicating whether the genre map has been created (only created once)
	static inline bool genreMapCreated{ false };

	// A bool indicating that there is at least one movie with multiple combinations of genres
	// For example, if the "Action" and "Drama" buttons are pressed and there is at least one movie
	// that has both the Action and Drama genres, this variable would be true.
	bool hasAllGenres{ false };

public:

	/* Constructs a new filter genre button
		\param posX: the x coordinate of the filtergenrebutton's position
		\param posY: the y coordinate of the filtergenrebutton's position
		\param text: the text displayed on the button
	*/
	FilterGenreButton(float posX, float posY, const std::string_view text, bool invisible = true);
	virtual ~FilterGenreButton() = default;

};




#endif