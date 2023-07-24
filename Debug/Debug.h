#pragma once

// Literal class Debug from Section 7.5.6

class Debug
{
private:
	bool hwerr; // Hardware errors
	bool ioerr; //IO errors
	bool othererr; // Other errors

public:
	constexpr Debug(bool b = true) : hwerr(b), ioerr(b), othererr(b) {};
	constexpr Debug(bool hw, bool io, bool oth) : hwerr(hw), ioerr(io), othererr(oth) {};
	constexpr bool any() const { return hwerr || ioerr || othererr; }
	void set_hwerr(bool b)		{ hwerr = b; }
	void set_ioerr(bool b)		{ ioerr = b; }
	void set_othererr(bool b)	{ othererr = b; }
};