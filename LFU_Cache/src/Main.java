import java.util.HashMap;
import java.util.LinkedHashSet;

class LFUCache {
    private final HashMap<Integer, Integer> cache = new HashMap<>();
    private final HashMap<Integer, Integer> freqMap = new HashMap<>();
    private final HashMap<Integer, LinkedHashSet<Integer>> freqList = new HashMap<>();
    private final int capacity;
    private int minFrequency = -1;

    public LFUCache(int capacity) {
      this.capacity = capacity;
      freqList.put(1, new LinkedHashSet<>());
      minFrequency = 1;
    }

    public int get(int key) {
       if (!cache.containsKey(key)) return -1;

       int cnt = freqMap.get(key);
       freqList.get(cnt).remove(key);

       if (freqList.get(minFrequency).size() == 0) ++minFrequency;

       if (!freqList.containsKey(cnt + 1)) freqList.put(cnt + 1, new LinkedHashSet<>());
       freqList.get(cnt + 1).add(key);

       freqMap.put(key, cnt + 1);

       return cache.get(key);
    }

    public void put(int key, int value) {
        if (capacity <= 0) return;

        if (cache.containsKey(key)) {
            cache.put(key, value);
            get(key);
            return;
        }

        if (cache.size() == capacity) {
            int evict = freqList.get(minFrequency).iterator().next();

            freqList.get(minFrequency).remove(evict);
            cache.remove(evict);
            freqMap.remove(evict);
        }

        cache.put(key, value);
        freqMap.put(key, 1);
        freqList.get(1).add(key);

        minFrequency = 1;
    }
}
