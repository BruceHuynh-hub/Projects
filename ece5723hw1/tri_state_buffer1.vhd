library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity tri_state_buffer is
port(inp, enable : IN std_logic; outp : OUT std_logic);
end entity tri_state_buffer;
architecture tri of tri_state_buffer is
begin
outp <= inp when enable = '1' else '0';
end architecture tri;

