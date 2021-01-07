class Buffer:

    def __init__(self, size):
        self.size = size
        self.end_time = []

    def delete_proced(self, request):
        while self.end_time:
            if self.end_time[0] <= request.arrival:
                self.end_time.pop(0)
            else:
                break

    def proc(self, request):
        """proces incoming request."""
        self.delete_proced(request)

        if len(self.end_time) == self.size: #if buffer is full
            return Response(True, -1)

        if len(self.end_time) == 0:   #if buffer is empty
            self.end_time = [request.arrival + request.proc_time]
            return Response(False, request.arrival)

        response = Response(False, self.end_time[-1])
        self.end_time.append(self.end_time[-1] + request.proc_time)
        return response


class Request:
    """Incoming network packet."""

    def __init__(self, arrival, proc_time):
        self.arrival = arrival
        self.proc_time = proc_time


class Response:
    """Response of the network buffer."""

    def __init__(self, dropped, start_time):
        self.dropped = dropped
        self.start_time = start_time


def read_requests(count):
    requests = []
    for i in range(count):
        arrival, proc_time = map(int, input().strip().split())
        requests.append(Request(arrival, proc_time))
    return requests


def proc_requests(requests, buffer):
    return [buffer.proc(r) for r in requests]


def print_responses(responses):
    for response in responses:
        print(response.start_time if not response.dropped else -1)


if __name__ == "__main__":
    size, count = map(int, input().strip().split())
    requests = read_requests(count)
    buffer = Buffer(size)
    responses = proc_requests(requests, buffer)

    print_responses(responses)