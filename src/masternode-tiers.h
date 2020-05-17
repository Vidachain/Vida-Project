// Copyright (c) 2020 The VIDA developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MASTERNODE_TIERS_H
#define MASTERNODE_TIERS_H

#include "amount.h"
#include "uint256.h"
#include "util.h"
enum MasternodeTiers { TIER_LONG = 0, TIER_SHORT, TIER_NONE};

const double MASTERNODE_TIER_COINS[MasternodeTiers::TIER_NONE] = {1500.0001, 2000.0001};
const double TIER_OBFUSCATION_VALUES[MasternodeTiers::TIER_NONE] = {1499.99, 1999.99};
const int MASTERNODE_TIER_COLLATERAL_MATURITY[MasternodeTiers::TIER_NONE] = {120000, 50000};

const int TIER_BLOCK_HEIGHT = 2300;

bool IsMasternodeOutput(CAmount nValue, int blockHeight);
unsigned int GetMasternodeTierFromOutput(CAmount nValue, int blockHeight);
double GetMastenodeTierCoins(unsigned int nTier);
unsigned int GetMastenodeTierMaturity(unsigned int nTier);
double GetObfuscationValueForTier(unsigned int nTier);
unsigned int CalculateWinningTier(const std::vector<size_t>& vecTierSizes, uint256 blockHash);

#endif
