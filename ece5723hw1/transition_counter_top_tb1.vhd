library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.ALL;

entity transition_counter_top_tb is
end transition_counter_top_tb;

architecture tb of transition_counter_top_tb is
	signal j, clk, start_input, end_input : std_logic := '0';
	signal rst : std_logic := '1';
	signal count : std_logic_vector (7 downto 0);

	
	begin
		UUT: entity work.trans_top port map(j => j, start_input => start_input, end_input => end_input, clk => clk, rst => rst, count => count);
		clk <= not clk after 50 ns;
		j <= not j after 14 ns;
		
		
		
		
	start_test : process
		begin
			
			rst <= '0' after 50 ns;
			wait for 100 ns;
			start_input <= '0';
			wait for 100 ns;
			start_input <= '1';
			wait for 100 ns;
			start_input <= '0';
			
			wait for 2000 ns;
			end_input<= '1';
			wait for 100 ns;
			end_input<= '0';
			
			wait for 2000 ns;
			start_input <= '0';
			wait for 100 ns;
			start_input <= '1';
			wait for 100 ns;
			start_input <= '0';
			wait for 2000 ns;
			rst <= '1';
			wait for 100 ns;
			rst <= '0';
			wait for 100 ns;

--			wait for 1000 ns;
--			start_input <= '1';
--			wait for 100 ns;
--			start_input <= '0';
			
--			wait for 1000 ns;
--			end_input<= '1';
--			wait for 100 ns;
--			end_input<= '0';
			
			
			
	wait;

			
	end process start_test;
end tb;
