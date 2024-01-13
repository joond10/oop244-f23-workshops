#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
namespace sdds {
	class Container {
		char* m_content; 
		size_t m_capacity;
		size_t m_volume;
	protected:
		Container& setEmpty();
		size_t capacity() const;
		size_t volume() const;
	public:
		Container(const char* content, size_t capacity, size_t volume = 0);
		~Container();
		size_t operator+=(size_t addValue);
		size_t operator-=(size_t subtractValue);
		operator bool() const;
		Container& clear(size_t capacity,const char* content);
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& ostr, const Container& contain);
	std::istream& operator>>(std::istream& istr, Container& contain);


}
#endif // !SDDS_CONTAINER_H
