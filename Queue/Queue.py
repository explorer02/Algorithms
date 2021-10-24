class MyQueue:
    def __init__(self, capacity):
        self.capacity = capacity
        self.queue = []
        self.front = 0
        self.rear = -1
        self.size = 0

    def isEmpty(self):
        return self.size == 0

    def isFull(self):
        return self.size == self.capacity

    def enqueue(self, data):
        if self.isFull():
            return
        self.rear = (self.rear + 1) % self.capacity
        self.queue.insert(self.rear, data)
        self.size += 1

    def dequeue(self):
        if self.isEmpty():
            return
        self.front = (self.front + 1) % self.capacity
        self.size -= 1

    def display(self):
        i = self.front
        j = 0
        while j < self.size:
            print(self.queue[i], end='\t')
            j += 1
            i = (i + 1) % self.capacity
        print('\n')


queue = MyQueue(4)
queue.enqueue(10)               #insertion
queue.enqueue(20)
queue.enqueue(30)           
queue.enqueue(40)
queue.display()
queue.dequeue()                 #deletion
queue.display()
