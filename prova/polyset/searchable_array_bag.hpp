#ifndef SEARCHABLE_ARRAY_BAG
#define SEARCHABLE_ARRAY_BAG

class searchable_array_bag : public searchable_bag, public array_bag{
  private:
  
  public:
  searchable_array_bag();
  searchable_array_bag(const searchable_array_bag &other);
  searchable_array_bag operator=(const searchable_array_bag &other);
  ~searchable_array_bag();

  bool has(int val) const;
};

#endif
