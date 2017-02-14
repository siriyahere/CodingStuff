class MinHeap{
	int *ptr;
	int capacity;
	int size;
	
	MinHeap(vector<int> &p){
		ptr=p;
		size=p.size();
		int i=(size-1)/2;
		while(i>=0){
			build_max_heap(i);
			i--;
		}
	}
	
	void build_min_heap(int i){
		
		int smallest=i;
		int l=left(i);
		int r=right(i);
		if(l<size&&A[l]<A[i])
			smallest=l;
		if(r<size&&A[r]<A[smallest])
			smalles=r;
		if(smallest!=i)
		{
			swap(&ptr[i],&ptr[smallest]);
			build_min_heap(smallest);
		}		
	}
	
	int extract_min(){
		if(heap_size==0)
			return INT_MAX;
		int element=p[0];
		if(heap_size>1){
			p[0]=p[heap_size-1];
			build_min_heap(0);
		}
		heap_size--;
		return element;
	}
	
};
