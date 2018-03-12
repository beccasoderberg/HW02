#ifndef ARRAY_BASED_PD_H_
#define ARRAY_BASED_PD_H_
#include <string>

/** Specification file for the array-based phone directory.
*/
class Phone_Directory
{
public:
	/** Construct an empty phone directory.
	*/
	Phone_Directory();

	/** Destroy the phone directory when it is no longer needed.
	*/
	~Phone_Directory();

	/** Load the data file containing the directory, or
	establish a connection with the data source.
	@param source_name The name of the file (data source)
	with the phone directory entries.
	*/
	void load_data(const std::string& source_name);

	/** Look up an entry.
	@param name The name of the person to look up
	@return The number associated with that person
	or an empty string if name is not in
	the directory
	*/
	std::string lookup_entry(const std::string& name) const;

	/** Changes the number associated with the given name to
	the new value, or adds a new entry with this name and
	number.
	@param name The name of the person
	@param number The new number
	@return The old value of number or an empty string
	if this is a new entry
	*/
	std::string add_or_change_entry(const std::string& name,
		const std::string& number);

	/** Removes the entry with the specified name from the directory.
	@param name The name of the person
	@return The person's name or an empty string if not in
	the directory
	*/
	std::string remove_entry(const std::string& name);

	/** Writes the contents of the directory to the data file.
	*/
	void save();


	class Directory_Entry

	{
	private: std::string the_name;
			 std::string the_number;

	public:

		Directory_Entry() {}

		Directory_Entry(std::string the_name, std::string the_number) {

			the_name = 'John';
			the_number = 5555555;

		}

		std::string get_name() const {

			return the_name;

		}

		std::string get_number() const {

			return the_number;

		}

		void set_number(const std::string& new_number) {

			the_number = new_number;

		}

	};

	// Private Functions
	/** Searches the array of directory entries for the name.
	@param name The name to be found
	@return The index of the entry containing the name, or size
	if the name is not found
	*/
	int find(const std::string& name) const;

	/** Adds a new entry with the given name and number to the array
	of directory entries.
	@param name The name to be added
	@param number The number to be added
	*/
	void add(const std::string& name, const std::string& number);

	/** Removes the entry at the given index.
	@param index The index of the entry to be removed
	*/
	void remove_entry(int index, const std::string& name, const std::string& number)
	{
		{
			index = find(name);
			if (index < size)
			{
				for (int i = 0; i < size; i++)
				{
					the_directory[i] = the_directory[i - 1];
				}
				size = size - 1;
			}
			modified = true;
		}
	}
	void reallocate();

	/** The number of entries in the directory. */
	int size;
	/** The current capacity of the array. */
	int capacity;
	/** Pointer to the array containing the directory data. */
	Directory_Entry* the_directory;
	/** The name of the data file that contains the directory data. */
	std::string source_name;
	/** Boolean flag to indicate whether the directory was
	modified since it was either loaded or saved. */
	bool modified;
};

#endif
