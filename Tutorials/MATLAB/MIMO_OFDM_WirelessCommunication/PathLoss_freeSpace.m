% Free Space path loss model
function pathLossDB = PathLoss_freeSpace(carrierFrequencyHz, ...
    distBaseToMobileStation, ...
    txAntennaGainDB, ...
    rxAntennaGainDB)

wavelength = 3e8/carrierFrequencyHz;
temp = wavelength ./ (4*pi*distBaseToMobileStation);

if nargin >  2
    temp  = temp * sqrt(txAntennaGainDB);
end

if nargin > 3
    temp = temp * sqrt(rxAntennaGainDB);
end

pathLossDB = -20 * log10(temp);
