#pragma once
#include <cstdint>
#include <map>
#include <vector>
#include <chrono>

enum class Side { BUY, SELL };
enum class OrderType { LIMIT, MARKET, CANCEL };

struct Order {
    uint64_t order_id;
    Side side;
    uint32_t price;
    uint32_t quantity;
    uint64_t timestamp_ns;
};

struct Trade {
    uint64_t maker_order_id;
    uint64_t taker_order_id;
    uint32_t execution_price;
    uint32_t executed_quantity;
};

class OrderBook {
private:
    std::map<uint32_t, std::vector<Order>, std::greater<uint32_t>> bids;
    std::map<uint32_t, std::vector<Order>> asks;

public:
    std::vector<Trade> match_order(const Order& incoming_order);
    void cancel_order(uint64_t order_id);
};
