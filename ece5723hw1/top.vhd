library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity trans_top is
port(j, start_input, end_input, clk, rst : IN std_logic; count : OUT std_logic_vector(7 downto 0));
end entity trans_top;

architecture top_level of trans_top is

component d_FF port(D, clk, rst : IN std_logic; Q : OUT std_logic);
end component;
component tri_state_buffer port(inp, enable : IN std_logic; outp : OUT std_logic);
end component;
component counter8bits port (counter_in, end_input, started, rst, clk : IN std_logic; counter_out : OUT std_logic_vector(7 downto 0));
end component;

signal two_to_one : std_logic;
signal one_to_zero : std_logic;
signal zero_out : std_logic;
signal is_it_starting : std_logic;
signal j_tri_enable : std_logic;
signal j_buffer_output : std_logic;
signal not_end_input : std_logic;
signal NEI_to_XOR : std_logic;
signal transition_FF_out : std_logic;
signal XOR_to_FF : std_logic ;
signal j_to_counter :std_logic;
signal counter_out_to_top :std_logic_vector(7 downto 0);
begin


-- end input(
not_end_input <= (not end_input);
-- )

--data path(

-- shift register(
FF2 : d_FF port map(D => start_input, clk => clk, rst => rst, Q => two_to_one);
FF1 : d_FF port map(D => two_to_one, clk => clk, rst => rst, Q => one_to_zero);
FF0 : d_FF port map(D => one_to_zero, clk => clk, rst => rst, Q => zero_out);
-- )

-- getting "010" from the registers (
is_it_starting <= (not two_to_one) AND one_to_zero AND (not zero_out) AND not_end_input;
-- )

-- monostable (
j_tri_enable <= is_it_starting OR j_tri_enable;
-- )

-- j input (
j_TS : tri_state_buffer port map(inp => j, enable => j_tri_enable, outp => j_buffer_output);

-- )

-- end input control (
end_input_TS : tri_state_buffer port map(inp => j_buffer_output, enable => not_end_input, outp => NEI_to_XOR);
-- )

-- transition FF (
transition_FF : d_FF port map(D => XOR_to_FF, clk => clk, rst => rst, Q => transition_FF_out);
-- )

-- XOR (

XOR_to_FF <= NEI_to_XOR XOR transition_FF_out;
-- )


-- end input control for counter (
end_input_TS2 : tri_state_buffer port map (inp => transition_FF_out, enable => not_end_input, outp => j_to_counter);
-- )

-- counter (
my_counter : counter8bits port map(counter_in => j_to_counter, end_input => end_input, started => is_it_starting, rst => rst, clk => clk, counter_out => counter_out_to_top);
-- )

count <= counter_out_to_top;



end architecture top_level;

