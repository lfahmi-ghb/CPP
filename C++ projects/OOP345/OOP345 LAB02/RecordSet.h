#pragma once
//Name: Lara Fahmi
//Student Number: 109742197

namespace sdds {
    class RecordSet {
    private:
        std::string* rec_str;
        std::size_t counter;

    public:
        RecordSet();
        RecordSet(char const* );
        ~RecordSet();
        RecordSet(RecordSet const& );
        RecordSet const& operator=(RecordSet const& );

        RecordSet(RecordSet&& oth) noexcept;
        RecordSet const& operator=(RecordSet&& ) noexcept;

        size_t size() const;
        std::string getRecord(std::size_t ) const;


    };
}


