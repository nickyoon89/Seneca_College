#ifndef KVLIST_H
#define KVLIST_H

template<typename K, typename V, int N>
class KVList {
	K _k[N];
	V _v[N];
	K kDummy;
	V vDummy;
	unsigned int count;
public:
	KVList() : kDummy{ 0 }, vDummy{ 0 }, count{0u} {}
	size_t fullsize() const { return sizeof(_k)/sizeof(K); }
	size_t size() const { return count; }
	const K& key(int i) const {
		if (static_cast<unsigned int>(i) < size()&&i >= 0) return _k[i];
		else return kDummy;
	}
	const V& value(int i) const {
		if (static_cast<unsigned int>(i) < size()&&i >= 0) return _v[i];
		else return vDummy;
	}
	KVList& add(const K& k, const V& v) {
		if (count < fullsize()) {
			_k[count] = k;
			_v[count] = v;
			count++;
		}
		return *this;
	}
	int find(const K& k) const {
		for (unsigned int i = 0; i < size(); i++)
		{
			if (_k[i] == k) {
				return i;
			}
		}
		return 0;
	}
	KVList& replace(int i, const K& k, const V& v) {
		if (static_cast<unsigned int>(i) < size()) {
			_k[i] = k;
			_v[i] = v;
		}
		return *this;
	}
};

#endif