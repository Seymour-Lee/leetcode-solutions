/**
    given the requirements below, design a simple stock exchange system

    - you have market price and internal price for each stock
    - each stock is assigned with an unique ID
    - you have two strateties: BUY and SELL
    - stock is allowed to be exchanged when they have both prices
    - if market price is higher than internal price, SELL
    - if market price is lower than internal price, BUY
    - strategies should be made at market prices and up to the market quantity

    - please implement the two methods below, to accept updates on the data:
        market_data_event(market_data &data)
        internal_data_event(internal_price_data &data)
**/

/**
    Modify your code according to the follow-ups:
    follow-up #1:
        what if we have an offset of price, meaning we don't BUY or SELL unless the market
        price is lower or higher than internal price minus an offset or plus an offset
    
    follow-up #2:
        what if we have two prices internally instead of one. Say we have a ask_price and a
        bid_price. We buy if market price is lower than the ask_price with an offset and sell 
        if the market price is higher than the bid_price with an offset.

    follow-up #3:
        what if we have two prices for the market, too. An ask_price and a bid_price, same idea
        as on the internal side.
**/

struct market_data
{
    unsigned id;
    int price;
    int quantity;
    
    // int ask_price;
    // int bid_price;
}

struct internal_price_data
{
    unsigned id;
    int price;
    int quantity;

    // int pirce_offset;
    // int ask_price;
    // int bid_price;
}

enum side
{
    BUY;
    SELL;
}

struct strategy_sender
{
    void send(unsigned id, int price, int quantity, side s);
}

struct stocksystem
{
void market_data_event(market_data &data) {}
void internal_data_event(internal_price_data &data) {}
private:
    strategy_sender sender_;
}

