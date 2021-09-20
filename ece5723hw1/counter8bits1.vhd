library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.ALL;
entity counter8bits is
port(counter_in, end_input, started, rst, clk : IN std_logic; counter_out : OUT std_logic_vector(7 downto 0));
end entity counter8bits;

architecture counting_arc of counter8bits is
signal current_count : std_logic_vector(7 downto 0);
type jstate is (nullState, start0, start1, change01, change10);
signal present_state : jstate;
signal next_state: jstate := nullState;
signal end1 : std_logic;
signal end2 : std_logic := '0';



signal int_count: integer := 0;
begin

present_state <= next_state when clk'event and clk = '1';

current_count <= std_logic_vector(to_unsigned(int_count, 8)) when rising_edge(clk);
counter_out <= current_count;

ending: process(clk)
begin
if started = '1' then
end2 <= '1';
elsif end_input = '1' then
end2 <= '0';
end if;
end process ending;




stacking: process(clk)
begin

next_state <= present_state;
int_count <= 0 when int_count = 255;
int_count <= 0 when rst = '1';	
				if end2 = '1' then
					case present_state is
					
						when nullState =>
							if (counter_in = '0') then
								next_state <= start0;
							else
								next_state <= start1;
							end if;
						
						when start0 =>
							if (counter_in = '1') then
								next_state <= change01;
								int_count <= int_count + 1;
							else
								next_state <= start0;
							end if;
						
						when start1 =>
							if (counter_in = '0') then
								next_state <= change10;
								int_count <= int_count + 1;
							else
								next_state <= start1;
							end if;
						
						when change01 =>
							if (counter_in = '0') then
								next_state <= change10;
								int_count <= int_count + 1;
							else
								next_state <= start1;
							end if;
						
						when change10 =>
							if (counter_in = '1') then
								next_state <= change01;
								int_count <= int_count + 1;
							else
								next_state <= start0;
							end if;
						when others =>
							next_state <= nullState;					

end case;
end if;
end process stacking;
end architecture counting_arc;
