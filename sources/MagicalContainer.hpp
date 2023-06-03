#pragma once

#include <vector>

using namespace std;

namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> elements;

    public:
        MagicalContainer();
        void addElement(int element);
        void removeElement(int element);

        // Returns the size of the vector
        size_t size() const { return elements.size(); }
        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            size_t currentIdx;
            AscendingIterator(MagicalContainer &container, size_t index);

        public:
            AscendingIterator(MagicalContainer &cont);
            AscendingIterator(const AscendingIterator &other);
            AscendingIterator(AscendingIterator &&other) noexcept;
            AscendingIterator &operator=(const AscendingIterator &other);
            AscendingIterator &operator=(AscendingIterator &&other) noexcept;
            ~AscendingIterator() = default;

            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;

            int operator*() const;

            AscendingIterator &operator++();
            AscendingIterator begin() { return AscendingIterator(container, 0); }
            AscendingIterator end() const { return AscendingIterator(container, container.size()); }
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &container;
            size_t currentIdx;
            SideCrossIterator(MagicalContainer &container, size_t index);

        public:
            SideCrossIterator(MagicalContainer &cont);
            SideCrossIterator(const SideCrossIterator &other);
            SideCrossIterator(SideCrossIterator &&other) noexcept;
            SideCrossIterator &operator=(const SideCrossIterator &other);
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;
            ~SideCrossIterator() = default;

            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;

            int operator*() const;

            SideCrossIterator &operator++();
            SideCrossIterator begin() { return SideCrossIterator(container, 0); }
            SideCrossIterator end() const { return SideCrossIterator(container, container.size()); }
        };

        class PrimeIterator
        {
        private:
            MagicalContainer &container;
            size_t currentIdx;
            PrimeIterator(MagicalContainer &container, size_t index);

        public:
            PrimeIterator(MagicalContainer &cont);
            PrimeIterator(const PrimeIterator &other);
            PrimeIterator(PrimeIterator &&other) noexcept;
            PrimeIterator &operator=(const PrimeIterator &other);
            PrimeIterator &operator=(PrimeIterator &&other) noexcept;
            ~PrimeIterator() = default;

            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;

            int operator*() const;

            PrimeIterator &operator++();
            PrimeIterator begin() { return PrimeIterator(container, 0); }
            PrimeIterator end() const { return PrimeIterator(container, container.size()); }
        };
    };
}